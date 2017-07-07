// Copyright 2015 All Rights Reserved.
// Author: eric@orangelab.cn (Cheng Xu)

#ifndef STREAM_SERVICE_IMPL_H__
#define STREAM_SERVICE_IMPL_H__

#include "stream_service/stream_service.grpc.pb.h"

namespace olive {
  using namespace google::protobuf;

class StreamServiceImpl : public StreamService::Service {
 public:
  //static void Init(int argc, char *argv[]);

  virtual grpc::Status CreateSession(grpc::ServerContext* context,
                                     const CreateSessionRequest* request,
                                     CreateSessionResponse* response);

  virtual grpc::Status CloseSession(grpc::ServerContext* context,
                                    const CloseSessionRequest* request,
                                    CloseSessionResponse* response);

  virtual grpc::Status CreateStream(grpc::ServerContext* context,
                                    const CreateStreamRequest* request,
                                    CreateStreamResponse* response);

  virtual grpc::Status CloseStream(grpc::ServerContext* context,
                                   const CloseStreamRequest* request,
                                   CloseStreamResponse* response);

  virtual grpc::Status SendSessionMessage(grpc::ServerContext* context,
                                          const SendSessionMessageRequest* request,
                                          SendSessionMessageResponse* response);

  virtual grpc::Status RecvSessionMessage(grpc::ServerContext* context,
                                          const RecvSessionMessageRequest* request,
                                          RecvSessionMessageResponse* response);
 private:
  void CreateMediaPipeline(int32 session_id, int32 stream_id);
  void FinishMediaPipeline(int32 session_id, int32 stream_id);
};

}  // namespace olive

#endif  // STREAM_SERVICE_IMPL_H__
