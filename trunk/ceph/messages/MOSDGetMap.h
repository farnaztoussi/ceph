// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*- 
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2004-2006 Sage Weil <sage@newdream.net>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software 
 * Foundation.  See file COPYING.
 * 
 */

#ifndef __MOSDGETMAP_H
#define __MOSDGETMAP_H

#include "msg/Message.h"

#include "include/types.h"

class MOSDGetMap : public Message {
 public:
  epoch_t start;

  MOSDGetMap(epoch_t s=0) : 
    Message(MSG_OSD_GETMAP),
    start(s) {
  }

  epoch_t get_start_epoch() { return start; }

  char *get_type_name() { return "get_osd_map"; }
  void print(ostream& out) {
    out << "get_osd_map(" << start << ")";
  }
  
  void encode_payload() {
    ::_encode(start, payload);
  }
  void decode_payload() {
    int off = 0;
    ::_decode(start, payload, off);
  }
};

#endif
