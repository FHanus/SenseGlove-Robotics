// SGCoreCpp_Standalone.cpp : Example to show how to build a SenseGlove project that's independent of the SenseCom program.
//

#include <iostream>
#include "SGConnect.h"
#include "DeviceList.h"
#include "SenseGlove.h"
#include "Library.h"

#include <thread>
#include <chrono> //wait untill we find SenseGloves

int main()
{
	std::cout << "Standalone Communications using " << SGConnect::GetLibraryVersion() << " and " << SGCore::Library::Version() << std::endl;
	std::cout << "============================================================================================" << std::endl << std::endl;

	std::cout << "The SGConnect library allows us to initialize and detect SenseGloves and other SenseGlove Devices" << std::endl;

	//---------------------------------------------------------------------------
	// SGConnect Initalization - Parts taken from the SGConnect example code.

	SGConnect::SetDebugLevel(0); //0 disables the Devug level, 1 shows you only the errors.

	bool scanActive = SGConnect::ScanningActive(); //this returns true if there is already a SGConnect process running (For instance, from SenseCom)
	if (!scanActive)
	{
		std::cout << "We call SGConnect::Init() to startup a background process, which will begin scanning for SenseGlove devices." << std::endl;
		int initCode = SGConnect::Init();
		if (initCode > 0)
		{
			std::cout << "Succesfully initialized background process: (InitCode = " << std::to_string(initCode) << ")" << std::endl;
			std::cout << "This process will begin connecting to ports that should belong to SenseGlove devices." << std::endl;
			std::cout << "It will take a few seconds before the devices appear to the SenseGlove API, especially when using Bluetooth devices." << std::endl;
			std::cout << "Below, you will see debug messages appear from the background process. Press return when you see one appear, or when you're ready to end." << std::endl;
			std::cout << "" << std::endl;
			while (std::cin.get() != '\n') {} //Wait for the user to confirm before continuing.
			std::cout << "" << std::endl;
		}
		else
		{
			std::cout << "Oddly enough, we could not initialize the SGConnect library. (InitCode = " << std::to_string(initCode) << ")" << std::endl;
			std::cout << "Please close this program, and try again." << std::endl;
		}
	}
	else
	{
		std::cout << "A SenseGlove scanning process is already running (ScanState " << std::to_string(SGConnect::ScanningState()) << " > 0)." << std::endl;
		std::cout << "Seeing as we've just started up, it can't possibly be this process that did it." << std::endl;
		std::cout << "It is safe to call SGConnect::Init() even if this is the case, but no new process will be started." << std::endl;
		int initCode = SGConnect::Init();
		std::cout << "The SGConnect::Init() will return 0, to let us know no Initialization was done: " << std::to_string(initCode) << std::endl << std::endl;
		std::cout << std::endl;
		
	}

	//---------------------------------------------------------------------------
	// SGCoreCpp  - Parts taken from the SGCoreCpp example code.

		{
		// For a more practical example: Let's assume this is 1 frame of your simulation.
		// You've defined which glove you want to use (left/right) - in this case, let's use the same side as our testGlove.
		std::shared_ptr<SGCore::HapticGlove> glove;
		if (SGCore::HapticGlove::GetGlove(glove))
		{
			//Step 1: Hand Pose
			std::cout << "Glove detected: " << glove->ToString() << std::endl;
			// We want to get the pose of the hand - to animate a virtual model
			while (true) {
				SGCore::HandPose handPose; //The handPose class contains all data you'll need to animate a virtual hand
				if (glove->GetHandPose(handPose)) //returns the HandPose based on the latest device data, using the latest Profile and the default HandGeometry
				{
					std::cout << "Retrieved the latest Hand Pose from " + glove->ToString() + ". The ToString() function reports important finger angles, in degrees, in our coodinate system:" << std::endl;
					std::cout << handPose.ToString() << std::endl;

					// The HandPose is still in our Coordinate System, relative to the wrist.
					// You'll need to convert our Vect3D and Quats to your own coordinate system. You can find an explanation of our Coordinate system at docs.senseglove.com/

					// We also offer "normalized" angles : Which gives you the total flexion of the finger(s) as a value between 0 and 1,
					// where 0 represents the fingers fully extended, and 1 represents the finger fully flexed.
					std::vector<float> flexions = handPose.GetNormalizedFlexion();
					std::string flexes = "";
					for (int i = 0; i < flexions.size(); i++)
					{
						flexes += std::to_string((int)std::round(flexions[i]));
						if (i < flexions.size() - 1) { flexes += ", "; }
					}
					std::cout << "Normalized finger flexions [" + flexes + "]" << std::endl;
					std::cout << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				else //This function could return false if no data for this glove is available (yet).
				{
					std::cout << "Something went wrong trying to access the HandPose of " + glove->ToString() + ". Try again later.";
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				

			}


	//---------------------------------------------------------------------------
	// SGConnect Cleanup - Parts taken from the SGConnect example code.
	
	std::cout << std::endl;
	if (!scanActive)
	{
		int disposeCode = SGConnect::Dispose();
		if (disposeCode > 0)
		{
			std::cout << "Succesfully cleaned up SGConnect resources: (DisposeCode = " << std::to_string(disposeCode) << ")" << std::endl;
			std::cout << "It's now safe to exit the program. Press return to end." << std::endl;
		}
		else
		{
			std::cout << "Unable to properly dispose of SGConnect resources: (DisposeCode = " << std::to_string(disposeCode) << ")." << std::endl;
			std::cout << "Fortunately, closing this process will cause them to go out of scope and be destroyed either way." << std::endl;
		}
	}
	else
	{
		std::cout << "Since this process did not start SGConnect, we don't need to clean anything up." << std::endl;
		std::cout << "We can call SGConnect::Dispose() safely, but this will not stop the original process." << std::endl;
		int disposeVal = SGConnect::Dispose();
		std::cout << "The SGConnect::Dispose() will return a value that is not 1, to let us know nothing was Disposed of: " << std::to_string(disposeVal) << std::endl;
		std::cout << "If you wish to dispose of the already running process, you should call SGConnect::Dispose() from the program that originally called SGConnect::Init()" << std::endl;
	}

	while (std::cin.get() != '\n') {} //Wait for the user to confirm before exiting.
	}
}