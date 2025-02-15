// Copyright 2019 ZTE corporation. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#ifndef ADLIK_SERVING_RUNTIME_LIBTORCH_MODEL_LIBTORCH_MODEL_H
#define ADLIK_SERVING_RUNTIME_LIBTORCH_MODEL_LIBTORCH_MODEL_H

#include <memory>

#include "adlik_serving/framework/domain/model_config.h"
#include "adlik_serving/framework/domain/model_id.h"
#include "adlik_serving/runtime/batching/batching_model.h"
#include "adlik_serving/runtime/batching/composite_batch_processor.h"
#include "cub/base/status.h"
#include "tensorflow/core/lib/core/status.h"

namespace libtorch_runtime {

struct LibtorchModel : adlik::serving::BatchingModel, adlik::serving::CompositeBatchProcessor {
  static cub::Status create(const adlik::serving::ModelConfig&,
                            const adlik::serving::ModelId&,
                            std::unique_ptr<LibtorchModel>*);

private:
  LibtorchModel(const adlik::serving::ModelConfig& config, const adlik::serving::ModelId& model_id);

  LibtorchModel(LibtorchModel&&) = delete;
  LibtorchModel(const LibtorchModel&) = delete;

  tensorflow::Status init();

  IMPL_ROLE_NS(adlik::serving, BatchProcessor);

  adlik::serving::ModelConfig config;
  adlik::serving::ModelId model_id;
};

}  // namespace libtorch_runtime

#endif
