/* GLoBES -- General LOng Baseline Experiment Simulator
 * (C) 2002 - 2007,  The GLoBES Team
 *
 * GLoBES is mainly intended for academic purposes. Proper
 * credit must be given if you use GLoBES or parts of it. Please
 * read the section 'Credit' in the README file.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
 /* 
 * Example: Correlation between s22th13 and deltacp
 * Compile with ``make example1''
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <globes/globes.h>   /* GLoBES library */
#include "myio.h"             /* my input-output routines */

/* If filename given, write to file; for empty filename write to screen */
char MYFILE[]="test1.dat";

FILE *f = fopen("chi2_vs_theta13.dat", "w");
for (double theta = 0.01; theta <= 0.1; theta += 0.001) {
    glbSetOscParams(...);  // set theta13
    double chi2 = glbChiSys(...);
    fprintf(f, "%f\t%f\n", theta, chi2);
}
fclose(f);

int main(int argc, char *argv[])
{ 
  /* Initialize libglobes */
  glbInit(argv[0]);

  /* Initialize experiment NFstandard.glb */
  glbInitExperiment("NFstandard.glb",&glb_experiment_list[0],&glb_num_of_exps); 
 
  /* Intitialize output */
  InitOutput(MYFILE,"Format: Log(10,s22th13)   deltacp   chi^2 \n"); 
  
  /* Define standard oscillation parameters */
  double theta12 = asin(sqrt(0.8))/2;
  double theta13 = asin(sqrt(0.001))/2;
  double theta23 = M_PI/4;
  double deltacp = M_PI/2;
  double sdm = 7e-5;
  double ldm = 2e-3;
  
  /* Initialize parameter vector(s) */
  glb_params true_values = glbAllocParams();
  glb_params test_values = glbAllocParams();

  glbDefineParams(true_values,theta12,theta13,theta23,deltacp,sdm,ldm);
  glbSetDensityParams(true_values,1.0,GLB_ALL);
  glbDefineParams(test_values,theta12,theta13,theta23,deltacp,sdm,ldm);  
  glbSetDensityParams(test_values,1.0,GLB_ALL);

  /* The simulated data are computed */
  glbSetOscillationParameters(true_values);
  glbSetRates();

  /* Iteration over all values to be computed */
  double thetheta13,x,y,res;    
    
  for(x=-4.0;x<-2.0+0.01;x=x+2.0/50)
  for(y=0.0;y<200.0+0.01;y=y+200.0/50)
  {
      /* Set vector of test values */
      thetheta13=asin(sqrt(pow(10,x)))/2;
      glbSetOscParams(test_values,thetheta13,GLB_THETA_13);
      glbSetOscParams(test_values,y*M_PI/180.0,GLB_DELTA_CP);
  
      /* Compute Chi^2 for all loaded experiments and all rules */
      res=glbChiSys(test_values,GLB_ALL,GLB_ALL);
      AddToOutput(x,y,res);
  }
   
  /* Destroy parameter vector(s) */
  glbFreeParams(true_values);
  glbFreeParams(test_values); 
  
  exit(0);
}
