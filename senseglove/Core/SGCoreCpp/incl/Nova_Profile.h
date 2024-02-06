// ----------------------------------------------------------------------------------
// Input for Nova kinematics to calculate a HandPose.
// Output of calibration algorithms.
// @author: Max Lammers
// ----------------------------------------------------------------------------------

#pragma once

#include "SGCore.h"

#include "HandInterpolator.h"
#include <string>
#include <vector>

namespace SGCore
{
	namespace Nova
	{
		/// <summary> Contains user-specific data for the Nova to convert sensor data into a hand pose. </summary>
		class SGCORE_API Nova_Profile
		{
			
		public:
			
			//--------------------------------------------------------------------------------------
			// Properties

			/// <summary> Whether this profile was created for a right- or left hand. </summary>
			bool isRight;

			/// <summary> Interpolation sets to convert sensor data into a hand pose. </summary>
			SGCore::Kinematics::HandInterpolator interpolationSet;


			//--------------------------------------------------------------------------------------
			// Construction

			/// <summary> Default constructor. </summary>
			/// <returns></returns>
			Nova_Profile();

			/// <summary> Create a new instance of a Nova-Profile. </summary>
			/// <param name="right"></param>
			/// <param name="interpolator"></param>
			/// <returns></returns>
			Nova_Profile(bool right, SGCore::Kinematics::HandInterpolator interpolator);
			
			/// <summary> Creates a default Nova Profile for a left or right hand. </summary>
			/// <param name="right"></param>
			/// <returns></returns>
			static Nova_Profile Default(bool right);


			//--------------------------------------------------------------------------------------
			// Class Methods

			/// <summary>  </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			bool Equals(Nova_Profile other);

			void Reset();

			//--------------------------------------------------------------------------------------
			// Serialization

            /// <summary> Convert this Nova_Profile into a string notation so it can be stored on disk. </summary>
            /// <returns></returns>
            std::string Serialize();

			/// <summary> Convert a string notation of a Nova_Profile into a new instance. </summary>
			/// <param name="serializedString"></param>
			/// <returns></returns>
			static Nova_Profile Deserialize(std::string serializedString);


		};
	}
}