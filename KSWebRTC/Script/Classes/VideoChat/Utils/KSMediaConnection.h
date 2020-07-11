//
//  KSMediaConnection.h
//  KSWebRTC
//
//  Created by saeipi on 2020/7/11.
//  Copyright © 2020 saeipi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebRTC/WebRTC.h>
@class KSMediaConnection;
@protocol KSPeerConnectionDelegate <NSObject>
// 收到远端流处理
- (void)MediaConnection:(KSMediaConnection *)mediaConnection peerConnection:(RTCPeerConnection *)peerConnection didAddStream:(RTCMediaStream *)stream;
// 收到候选者
- (void)MediaConnection:(KSMediaConnection *)mediaConnection peerConnection:(RTCPeerConnection *)peerConnection
didGenerateIceCandidate:(RTCIceCandidate *)candidate;

@end

@interface KSMediaConnection : NSObject

@property (nonatomic, weak) id<KSPeerConnectionDelegate> delegate;
@property (nonatomic, strong) RTCPeerConnection *connection; // WebRTC连接对象
@property (nonatomic, strong) RTCVideoTrack *videoTrack;     // 视频轨
@property (nonatomic, strong) RTCEAGLVideoView *videoView;

- (RTCPeerConnection *)createPeerConnection:(RTCPeerConnectionFactory *)factory
                                 audioTrack:(RTCAudioTrack *)audioTrack
                                 videoTrack:(RTCVideoTrack *)videoTrack;

- (void)createOfferWithCompletionHandler:
        (nullable void (^)(RTCSessionDescription *sdp, NSError *error))completionHandler;

// 创建answer
- (void)createAnswerWithCompletionHandler:
        (nullable void (^)(RTCSessionDescription *sdp, NSError *error))completionHandler;

- (void)setRemoteDescriptionWithJsep:(NSDictionary *)jsep;

- (void)close;

@end