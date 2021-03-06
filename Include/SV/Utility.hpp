#ifndef SV_UTILITY_HPP
#define SV_UTILITY_HPP


#include <opencv2/core/core.hpp>

#include <string>
#include <array>
#include <utility>


namespace SV
{
	/* Camera Parameters */
    extern const int           	MAX_NUMBER_OF_CAMERAS;
    extern const char*         	CONFIGURATION_FILE;
    extern int                 	MAIN_LOOP_ITERATION_TIME;
    extern const int           	INTER_PACKET_DELAY;
    extern const int           	FRAME_TRANSMISSION_DELAY;

    
    /* Calibration Parameters */
    extern const std::string    CALIBRATION_BIN;
    extern const std::string	CALIBRATION_TIMESTAMP_FILE;
    extern const std::string    CALIBRATION_PATTERN_FILE;
    extern const std::string    CALIBRATION_XML_FILES_PATH;
    extern const std::string    CALIBRATION_IMAGES_FILE;
    extern const std::string    CALIBRATION_IMAGES_PATH;
    extern const std::string    CALIBRATION_IMAGE_LEFT;
    extern const std::string    CALIBRATION_IMAGE_RIGHT;
    extern const std::string	NOT_CALIBRATED;

    struct CalibrationPattern
    {
        CalibrationPattern(unsigned int cornersWidth, unsigned int cornersHeight, float squareSize)
        : w(cornersWidth)
        , h(cornersHeight)
        , s(squareSize)
        {            
        }

        unsigned int    w;
        unsigned int    h;
        float           s;
    };

    struct StereoPhoto
    {
        std::array<std::string, 2>  cameras;
        std::pair<cv::Mat, cv::Mat> matPair;
    };
    


    /* Emulation Parameters */
    extern bool                 EMULATION_MODE;
    extern const std::string    EMULATED_CAMERA;
    extern const std::string    EMULATED_IMAGES_FILE;
    extern const std::string    EMULATED_IMAGES_PATH;


    /* Other Parameters */
    extern const std::string	lineBreak;


    /* Functions */
    std::string                 getTimestamp();
    std::string                 loadCalibrationTimestampFile();
    void                        saveCalibrationTimestampFile();
    CalibrationPattern          loadCalibrationPatternFile();
    void                        saveCalibrationPatternFile(unsigned int w, unsigned int h, float s);
    int                         forkExecStereoCalibrationModule(unsigned int w, unsigned int h, float s);
    cv::Scalar                  openCVRandomColor(cv::RNG& rng);
}

#endif // SV_UTILITY_HPP
