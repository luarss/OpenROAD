///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2022, The Regents of the University of California
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// Generator Code Begin Header
#pragma once

#include <string>

#include "dbCore.h"
#include "dbScanPin.h"
#include "dbVector.h"
#include "odb/odb.h"

namespace odb {
class dbIStream;
class dbOStream;
class _dbDatabase;
class _dbScanPartition;
template <class T>
class dbTable;
class dbScanPin;

class _dbScanChain : public _dbObject
{
 public:
  _dbScanChain(_dbDatabase*);

  ~_dbScanChain();

  bool operator==(const _dbScanChain& rhs) const;
  bool operator!=(const _dbScanChain& rhs) const { return !operator==(rhs); }
  bool operator<(const _dbScanChain& rhs) const;
  dbObjectTable* getObjectTable(dbObjectType type);
  void collectMemInfo(MemInfo& info);
  // User Code Begin Methods
  std::variant<dbBTerm*, dbITerm*> getPin(const dbId<dbScanPin>& scan_pin_id);
  void setPin(dbId<dbScanPin> _dbScanChain::*field, dbBTerm* pin);
  void setPin(dbId<dbScanPin> _dbScanChain::*field, dbITerm* pin);
  // User Code End Methods

  std::string name_;
  dbId<dbScanPin> scan_in_;
  dbId<dbScanPin> scan_out_;
  dbId<dbScanPin> scan_enable_;
  dbId<dbScanPin> test_mode_;
  std::string test_mode_name_;
  dbTable<_dbScanPartition>* scan_partitions_;
};
dbIStream& operator>>(dbIStream& stream, _dbScanChain& obj);
dbOStream& operator<<(dbOStream& stream, const _dbScanChain& obj);
}  // namespace odb
   // Generator Code End Header
