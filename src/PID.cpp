#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    /*PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    */
    p[0] = Kp; p[1] = Kd; p[2] = Ki;
}

void PID::UpdateError(double cte) {
    updateCount++;

    prev_cte = PID::cte;
    PID::cte = cte;
    sum += cte;

    p_error = cte;
    i_error = sum;
    d_error = cte - prev_cte;

    // do twiddle

    double error = TotalError();

    if (step == 0) {
      	p[currIdx] += dp[currIdx];
	step++;
    } else if (step == 1) {
        if (error < best_error) {
            best_error = error;
            dp[currIdx] *= 1.1;
	    currIdx++;
            step = 0;
        } else {
            p[currIdx] -= 2 * dp[currIdx];
            step++; 
	}
    } else {
	if (error < best_error) {
 	    best_error = error;	
	    dp[currIdx] *= 1.1;
	} else {
	    p[currIdx] += dp[currIdx];
	    dp[currIdx] *= 0.9;
	}
        step = 0;
        currIdx = (currIdx + 1) % 3;
    }
}

double PID::TotalError() {
   return -p_error * p[0] - d_error * p[1] - d_error * p[2];
}

