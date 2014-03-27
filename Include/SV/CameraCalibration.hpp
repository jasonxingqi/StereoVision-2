#ifndef SV_CAMERACALIBRATION_HPP
#define SV_CAMERACALIBRATION_HPP


#include <pylon/ImageEventHandler.h>

#include <string>
#include <mutex>


namespace Pylon
{
    class CInstantCamera;
    class CGrabResultPtr;
}

class CameraCalibration : public Pylon::CImageEventHandler
{
	public:
						CameraCalibration(std::string cameraName, unsigned int* grabCountPtr, bool emulated);

		virtual void	OnImageGrabbed(Pylon::CInstantCamera& camera, const Pylon::CGrabResultPtr& grabResultPtr);


	private:
		std::string		mCameraName;
		unsigned int* 	mGrabCountPtr;		
		bool			mEmulated;
};

#endif // SV_CAMERACALIBRATION_HPP
