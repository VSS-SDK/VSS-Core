//
// Created by johnathan on 29/05/18.
//

#include "Helpers/DebugMapper.h"

namespace vss {
    namespace DebugMapper {

        vss_debug::Global_Debug debugToGlobalDebug(Debug debug) {
            vss_debug::Global_Debug globalDebug;

            for(unsigned int i = 0 ; i < debug.stepPoints.size() ; i++){
                auto stepPose = globalDebug.add_step_poses();
                setupStepPoint(stepPose, debug.stepPoints[i]);
            }

            for(unsigned int i = 0 ; i < debug.finalPoses.size() ; i++){
                auto finalPose = globalDebug.add_final_poses();
                setupFinalPose(finalPose, debug.finalPoses[i]);
            }

            for(unsigned int i = 0 ; i < debug.paths.size() ; i++){
                auto path = globalDebug.add_paths();
                setupPath(path, debug.paths[i]);
            }

            return globalDebug;
        }

        void setupStepPoint(vss_debug::Pose *stepPose, Point point) {
            stepPose->set_id(0);
            stepPose->set_x(point.x);
            stepPose->set_y(point.y);
            stepPose->set_yaw(0);
        }

        void setupFinalPose(vss_debug::Pose *finalPose, Pose pose) {
            finalPose->set_id(0);
            finalPose->set_x(pose.x);
            finalPose->set_y(pose.y);
            finalPose->set_yaw(pose.angle);
        }

        void setupPath(vss_debug::Path *vssPath, Path path) {
            for(unsigned int i = 0 ; i < path.points.size() ; i++){
                auto pose = vssPath->add_poses();
                setupStepPoint(pose, path.points[i]);
            }
        }
    }
}
