//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreCoord_Utils.h                                             //
//  Project   : CoreCoord                                                     //
//  Date      : Nov 23, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

//----------------------------------------------------------------------------//
// Namespaces                                                                 //
//----------------------------------------------------------------------------//
// All classes of this core is placed inside this namespace.
// We use MACROS so is easier to change if needed.
// Is (in our opinion) more explicit.
// And finally the editors will not reformat the code.
#define NS_CORECOORD_BEGIN namespace CoreCoord {
#define NS_CORECOORD_END   }
#define USING_NS_CORECOORD using namespace CoreCoord


//----------------------------------------------------------------------------//
// Version                                                                    //
//----------------------------------------------------------------------------//
#define COW_CORECOORD_VERSION_MAJOR    "0"
#define COW_CORECOORD_VERSION_MINOR    "3"
#define COW_CORECOORD_VERSION_REVISION "0"

#define COW_CORECOORD_VERSION       \
    COW_CORECOORD_VERSION_MAJOR "." \
    COW_CORECOORD_VERSION_MINOR "." \
    COW_CORECOORD_VERSION_REVISION
