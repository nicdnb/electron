// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/common/api/file_output_stream.h"

namespace atom {

FileOutputStream::FileOutputStream(base::File* file) : file_(file) {}

bool FileOutputStream::IsComplete() const {
  return is_complete_;
}

int FileOutputStream::GetChunkSize() {
  return 65536;
}

void FileOutputStream::EndOfStream() {
  is_complete_ = true;
}

v8::OutputStream::WriteResult FileOutputStream::WriteAsciiChunk(char* data,
                                                                int size) {
  auto bytes_written = file_->WriteAtCurrentPos(data, size);
  return bytes_written == size ? kContinue : kAbort;
}

}  // namespace atom
