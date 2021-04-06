/*
 *--------------------------------------------------------------------------------------------------
 * DXSLAM: A Robust and Efficient Visual SLAM System with Deep Features
 *　Author(s):
 * Dongjiang Li, Xuesong Shi, Qiwei Long, Shenghui Liu, Wei Yang, Fangshi Wang, Qi Wei, Fei Qiao qiaofei@mail.tsinghua.edu.cn
 * --------------------------------------------------------------------------------------------------
 * DXSLAM shows that deep CNN-based features can be well incorporated into modern SLAM systems, 
 * and significantly improve the system’s performance. DXSLAM is based on the famous ORB-SLAM2. 
 * If you haven't learn ORB_SLAM2 code, you'd better to be familiar with ORB_SLAM2 project first.
 *　@article{murORB2,
 *　title={{ORB-SLAM2}: an Open-Source {SLAM} System for Monocular, Stereo and {RGB-D} Cameras},
 *　author={Mur-Artal, Ra\'ul and Tard\'os, Juan D.},
 * journal={IEEE Transactions on Robotics},
 *　volume={33},
 * number={5},
 * pages={1255--1262},
 * doi = {10.1109/TRO.2017.2705103},
 * year={2017}
 *　}
 * --------------------------------------------------------------------------------------------------
 * Copyright (C) 2020, iVip Lab @ EE, THU (https://ivip-tsinghua.github.io/iViP-Homepage/). All rights reserved.
 * Licensed under the GPLv3 License;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://github.com/ivipsourcecode/dxslam/blob/master/License-gpl.txt
 *--------------------------------------------------------------------------------------------------
 */
#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include"Map.h"
#include"MapPoint.h"
#include"KeyFrame.h"
#include<pangolin/pangolin.h>

#include<mutex>

namespace DXSLAM
{

class MapDrawer
{
public:
    MapDrawer(Map* pMap, const std::string &strSettingPath);

    Map* mpMap;

    void DrawMapPoints();
    void DrawKeyFrames(const bool bDrawKF, const bool bDrawGraph);
    void DrawCurrentCamera(pangolin::OpenGlMatrix &Twc);
    void SetCurrentCameraPose(const cv::Mat &Tcw);
    void SetReferenceKeyFrame(KeyFrame *pKF);
    void GetCurrentOpenGLCameraMatrix(pangolin::OpenGlMatrix &M);

private:

    float mKeyFrameSize;
    float mKeyFrameLineWidth;
    float mGraphLineWidth;
    float mPointSize;
    float mCameraSize;
    float mCameraLineWidth;

    cv::Mat mCameraPose;

    std::mutex mMutexCamera;
};

} //namespace ORB_SLAM

#endif // MAPDRAWER_H
