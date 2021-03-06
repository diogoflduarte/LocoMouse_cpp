/*	Defining the TM variation of LocoMouse.

The TM version of LocoMouse is defined as inheriting the default LocoMouse algorithm and modifying some methods.

Author: Joao Fayad (joaofayad@gmail.com)

Note: The TM adaptations were originally developed by Dana Darmohrray in MATLAB.

*/

#ifndef __LocoMouse_TM_H_INCLUDED__
#define __LocoMouse_TM_H_INCLUDED__

#include "LocoMouse_class.hpp"

class LocoMouse_TM : public LocoMouse {
protected:
	//Parameters that are specific to this method:
	cv::Mat DISK_FILTER; //Disk filter for filtering the image and compute BB

	//Other parameters for BB computation:
	double BOTTOM_THRESHOLD = 2.55, SIDE_THRESHOLD = 2.55; //0.01 in [0 255] range.
	int MIN_VIS_PIXEL = 1, MIN_PIXEL_COUNT = 500;
	
	//Zeroing out cols and rows for background subtraction: These parameters are hardcoded and specific to the setups where these methods were developed.
	int ZERO_COL_PRE = 46, ZERO_COL_POST = 760;
	int ZERO_ROW_PRE = 100, ZERO_ROW_POST = 149;

	void imfill(const Mat &Iin, Mat &Iout);

	cv::Mat bwAreaOpen(cv::Mat &Iin);

private:
	//Computing BB for the TM setup:
	void computeMouseBox_DD(cv::Mat &I_side_view, double& bb_x);


public:
	LocoMouse_TM(LocoMouse_ParseInputs INPUTS);
	
	virtual void readFrame(); //Overloaded to perform post-processing steps
	
	virtual void computeBoundingBox(); //Overloaded to compute it in the new way.

};

#endif
