#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  //double Kp;
  //double Ki;
  //double Kd;

  double p[3];

  double prev_cte;
  double sum;
  double cte;

  double dp[3] = {0.01, 0.1, 0.0001};
  double best_error = 10000.0;

  int currIdx = 0;
  int step = 0;

  int updateCount = 0;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
