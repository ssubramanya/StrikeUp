// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Trades.proto

#include "Trades.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_Trades_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TradeInfo_Trades_2eproto;
class TradeInfoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TradeInfo> _instance;
} _TradeInfo_default_instance_;
class TradesDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Trades> _instance;
} _Trades_default_instance_;
static void InitDefaultsscc_info_TradeInfo_Trades_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_TradeInfo_default_instance_;
    new (ptr) ::TradeInfo();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::TradeInfo::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TradeInfo_Trades_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_TradeInfo_Trades_2eproto}, {}};

static void InitDefaultsscc_info_Trades_Trades_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Trades_default_instance_;
    new (ptr) ::Trades();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Trades::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Trades_Trades_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Trades_Trades_2eproto}, {
      &scc_info_TradeInfo_Trades_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Trades_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Trades_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Trades_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Trades_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::TradeInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::TradeInfo, price_),
  PROTOBUF_FIELD_OFFSET(::TradeInfo, quantity_),
  PROTOBUF_FIELD_OFFSET(::TradeInfo, bidorderid_),
  PROTOBUF_FIELD_OFFSET(::TradeInfo, askorderid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Trades, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Trades, trades_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::TradeInfo)},
  { 9, -1, sizeof(::Trades)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_TradeInfo_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Trades_default_instance_),
};

const char descriptor_table_protodef_Trades_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Trades.proto\"T\n\tTradeInfo\022\r\n\005price\030\001 \001"
  "(\001\022\020\n\010quantity\030\002 \001(\004\022\022\n\nbidOrderId\030\003 \001(\004"
  "\022\022\n\naskOrderId\030\004 \001(\004\"$\n\006Trades\022\032\n\006trades"
  "\030\001 \003(\0132\n.TradeInfob\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Trades_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_Trades_2eproto_sccs[2] = {
  &scc_info_TradeInfo_Trades_2eproto.base,
  &scc_info_Trades_Trades_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Trades_2eproto_once;
static bool descriptor_table_Trades_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Trades_2eproto = {
  &descriptor_table_Trades_2eproto_initialized, descriptor_table_protodef_Trades_2eproto, "Trades.proto", 146,
  &descriptor_table_Trades_2eproto_once, descriptor_table_Trades_2eproto_sccs, descriptor_table_Trades_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_Trades_2eproto::offsets,
  file_level_metadata_Trades_2eproto, 2, file_level_enum_descriptors_Trades_2eproto, file_level_service_descriptors_Trades_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_Trades_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_Trades_2eproto), true);

// ===================================================================

void TradeInfo::InitAsDefaultInstance() {
}
class TradeInfo::_Internal {
 public:
};

TradeInfo::TradeInfo()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:TradeInfo)
}
TradeInfo::TradeInfo(const TradeInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&price_, &from.price_,
    static_cast<size_t>(reinterpret_cast<char*>(&askorderid_) -
    reinterpret_cast<char*>(&price_)) + sizeof(askorderid_));
  // @@protoc_insertion_point(copy_constructor:TradeInfo)
}

void TradeInfo::SharedCtor() {
  ::memset(&price_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&askorderid_) -
      reinterpret_cast<char*>(&price_)) + sizeof(askorderid_));
}

TradeInfo::~TradeInfo() {
  // @@protoc_insertion_point(destructor:TradeInfo)
  SharedDtor();
}

void TradeInfo::SharedDtor() {
}

void TradeInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TradeInfo& TradeInfo::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TradeInfo_Trades_2eproto.base);
  return *internal_default_instance();
}


void TradeInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:TradeInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&price_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&askorderid_) -
      reinterpret_cast<char*>(&price_)) + sizeof(askorderid_));
  _internal_metadata_.Clear();
}

const char* TradeInfo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // double price = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 9)) {
          price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // uint64 quantity = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          quantity_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint64 bidOrderId = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          bidorderid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint64 askOrderId = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          askorderid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TradeInfo::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:TradeInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double price = 1;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(1, this->_internal_price(), target);
  }

  // uint64 quantity = 2;
  if (this->quantity() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(2, this->_internal_quantity(), target);
  }

  // uint64 bidOrderId = 3;
  if (this->bidorderid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(3, this->_internal_bidorderid(), target);
  }

  // uint64 askOrderId = 4;
  if (this->askorderid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(4, this->_internal_askorderid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TradeInfo)
  return target;
}

size_t TradeInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TradeInfo)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double price = 1;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    total_size += 1 + 8;
  }

  // uint64 quantity = 2;
  if (this->quantity() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_quantity());
  }

  // uint64 bidOrderId = 3;
  if (this->bidorderid() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_bidorderid());
  }

  // uint64 askOrderId = 4;
  if (this->askorderid() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_askorderid());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TradeInfo::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TradeInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const TradeInfo* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TradeInfo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TradeInfo)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TradeInfo)
    MergeFrom(*source);
  }
}

void TradeInfo::MergeFrom(const TradeInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TradeInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.price() <= 0 && from.price() >= 0)) {
    _internal_set_price(from._internal_price());
  }
  if (from.quantity() != 0) {
    _internal_set_quantity(from._internal_quantity());
  }
  if (from.bidorderid() != 0) {
    _internal_set_bidorderid(from._internal_bidorderid());
  }
  if (from.askorderid() != 0) {
    _internal_set_askorderid(from._internal_askorderid());
  }
}

void TradeInfo::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TradeInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TradeInfo::CopyFrom(const TradeInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TradeInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TradeInfo::IsInitialized() const {
  return true;
}

void TradeInfo::InternalSwap(TradeInfo* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(price_, other->price_);
  swap(quantity_, other->quantity_);
  swap(bidorderid_, other->bidorderid_);
  swap(askorderid_, other->askorderid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata TradeInfo::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Trades::InitAsDefaultInstance() {
}
class Trades::_Internal {
 public:
};

Trades::Trades()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Trades)
}
Trades::Trades(const Trades& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      trades_(from.trades_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Trades)
}

void Trades::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Trades_Trades_2eproto.base);
}

Trades::~Trades() {
  // @@protoc_insertion_point(destructor:Trades)
  SharedDtor();
}

void Trades::SharedDtor() {
}

void Trades::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Trades& Trades::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Trades_Trades_2eproto.base);
  return *internal_default_instance();
}


void Trades::Clear() {
// @@protoc_insertion_point(message_clear_start:Trades)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  trades_.Clear();
  _internal_metadata_.Clear();
}

const char* Trades::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .TradeInfo trades = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_trades(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Trades::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Trades)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .TradeInfo trades = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_trades_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_trades(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Trades)
  return target;
}

size_t Trades::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Trades)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .TradeInfo trades = 1;
  total_size += 1UL * this->_internal_trades_size();
  for (const auto& msg : this->trades_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Trades::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Trades)
  GOOGLE_DCHECK_NE(&from, this);
  const Trades* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Trades>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Trades)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Trades)
    MergeFrom(*source);
  }
}

void Trades::MergeFrom(const Trades& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Trades)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  trades_.MergeFrom(from.trades_);
}

void Trades::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Trades)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Trades::CopyFrom(const Trades& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Trades)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Trades::IsInitialized() const {
  return true;
}

void Trades::InternalSwap(Trades* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  trades_.InternalSwap(&other->trades_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Trades::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::TradeInfo* Arena::CreateMaybeMessage< ::TradeInfo >(Arena* arena) {
  return Arena::CreateInternal< ::TradeInfo >(arena);
}
template<> PROTOBUF_NOINLINE ::Trades* Arena::CreateMaybeMessage< ::Trades >(Arena* arena) {
  return Arena::CreateInternal< ::Trades >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
