// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Intmessage.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Intmessage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Intmessage_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Intmessage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Intmessage_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Intmessage_2eproto;
namespace a {
class IntMessage;
struct IntMessageDefaultTypeInternal;
extern IntMessageDefaultTypeInternal _IntMessage_default_instance_;
class voidMessage;
struct voidMessageDefaultTypeInternal;
extern voidMessageDefaultTypeInternal _voidMessage_default_instance_;
}  // namespace a
PROTOBUF_NAMESPACE_OPEN
template<> ::a::IntMessage* Arena::CreateMaybeMessage<::a::IntMessage>(Arena*);
template<> ::a::voidMessage* Arena::CreateMaybeMessage<::a::voidMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace a {

// ===================================================================

class IntMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:a.IntMessage) */ {
 public:
  inline IntMessage() : IntMessage(nullptr) {}
  ~IntMessage() override;
  explicit PROTOBUF_CONSTEXPR IntMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  IntMessage(const IntMessage& from);
  IntMessage(IntMessage&& from) noexcept
    : IntMessage() {
    *this = ::std::move(from);
  }

  inline IntMessage& operator=(const IntMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline IntMessage& operator=(IntMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const IntMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const IntMessage* internal_default_instance() {
    return reinterpret_cast<const IntMessage*>(
               &_IntMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(IntMessage& a, IntMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(IntMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(IntMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  IntMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<IntMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const IntMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const IntMessage& from) {
    IntMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(IntMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "a.IntMessage";
  }
  protected:
  explicit IntMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumberFieldNumber = 1,
  };
  // int32 number = 1;
  void clear_number();
  int32_t number() const;
  void set_number(int32_t value);
  private:
  int32_t _internal_number() const;
  void _internal_set_number(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:a.IntMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int32_t number_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Intmessage_2eproto;
};
// -------------------------------------------------------------------

class voidMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:a.voidMessage) */ {
 public:
  inline voidMessage() : voidMessage(nullptr) {}
  ~voidMessage() override;
  explicit PROTOBUF_CONSTEXPR voidMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  voidMessage(const voidMessage& from);
  voidMessage(voidMessage&& from) noexcept
    : voidMessage() {
    *this = ::std::move(from);
  }

  inline voidMessage& operator=(const voidMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline voidMessage& operator=(voidMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const voidMessage& default_instance() {
    return *internal_default_instance();
  }
  enum NumCase {
    kIntNum = 1,
    kFloatNum = 2,
    kStringNum = 3,
    NUM_NOT_SET = 0,
  };

  static inline const voidMessage* internal_default_instance() {
    return reinterpret_cast<const voidMessage*>(
               &_voidMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(voidMessage& a, voidMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(voidMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(voidMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  voidMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<voidMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const voidMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const voidMessage& from) {
    voidMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(voidMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "a.voidMessage";
  }
  protected:
  explicit voidMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIntNumFieldNumber = 1,
    kFloatNumFieldNumber = 2,
    kStringNumFieldNumber = 3,
  };
  // int32 int_num = 1;
  bool has_int_num() const;
  private:
  bool _internal_has_int_num() const;
  public:
  void clear_int_num();
  int32_t int_num() const;
  void set_int_num(int32_t value);
  private:
  int32_t _internal_int_num() const;
  void _internal_set_int_num(int32_t value);
  public:

  // float float_num = 2;
  bool has_float_num() const;
  private:
  bool _internal_has_float_num() const;
  public:
  void clear_float_num();
  float float_num() const;
  void set_float_num(float value);
  private:
  float _internal_float_num() const;
  void _internal_set_float_num(float value);
  public:

  // string string_num = 3;
  bool has_string_num() const;
  private:
  bool _internal_has_string_num() const;
  public:
  void clear_string_num();
  const std::string& string_num() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_string_num(ArgT0&& arg0, ArgT... args);
  std::string* mutable_string_num();
  PROTOBUF_NODISCARD std::string* release_string_num();
  void set_allocated_string_num(std::string* string_num);
  private:
  const std::string& _internal_string_num() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_string_num(const std::string& value);
  std::string* _internal_mutable_string_num();
  public:

  void clear_num();
  NumCase num_case() const;
  // @@protoc_insertion_point(class_scope:a.voidMessage)
 private:
  class _Internal;
  void set_has_int_num();
  void set_has_float_num();
  void set_has_string_num();

  inline bool has_num() const;
  inline void clear_has_num();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    union NumUnion {
      constexpr NumUnion() : _constinit_{} {}
        ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
      int32_t int_num_;
      float float_num_;
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr string_num_;
    } num_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    uint32_t _oneof_case_[1];

  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Intmessage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// IntMessage

// int32 number = 1;
inline void IntMessage::clear_number() {
  _impl_.number_ = 0;
}
inline int32_t IntMessage::_internal_number() const {
  return _impl_.number_;
}
inline int32_t IntMessage::number() const {
  // @@protoc_insertion_point(field_get:a.IntMessage.number)
  return _internal_number();
}
inline void IntMessage::_internal_set_number(int32_t value) {
  
  _impl_.number_ = value;
}
inline void IntMessage::set_number(int32_t value) {
  _internal_set_number(value);
  // @@protoc_insertion_point(field_set:a.IntMessage.number)
}

// -------------------------------------------------------------------

// voidMessage

// int32 int_num = 1;
inline bool voidMessage::_internal_has_int_num() const {
  return num_case() == kIntNum;
}
inline bool voidMessage::has_int_num() const {
  return _internal_has_int_num();
}
inline void voidMessage::set_has_int_num() {
  _impl_._oneof_case_[0] = kIntNum;
}
inline void voidMessage::clear_int_num() {
  if (_internal_has_int_num()) {
    _impl_.num_.int_num_ = 0;
    clear_has_num();
  }
}
inline int32_t voidMessage::_internal_int_num() const {
  if (_internal_has_int_num()) {
    return _impl_.num_.int_num_;
  }
  return 0;
}
inline void voidMessage::_internal_set_int_num(int32_t value) {
  if (!_internal_has_int_num()) {
    clear_num();
    set_has_int_num();
  }
  _impl_.num_.int_num_ = value;
}
inline int32_t voidMessage::int_num() const {
  // @@protoc_insertion_point(field_get:a.voidMessage.int_num)
  return _internal_int_num();
}
inline void voidMessage::set_int_num(int32_t value) {
  _internal_set_int_num(value);
  // @@protoc_insertion_point(field_set:a.voidMessage.int_num)
}

// float float_num = 2;
inline bool voidMessage::_internal_has_float_num() const {
  return num_case() == kFloatNum;
}
inline bool voidMessage::has_float_num() const {
  return _internal_has_float_num();
}
inline void voidMessage::set_has_float_num() {
  _impl_._oneof_case_[0] = kFloatNum;
}
inline void voidMessage::clear_float_num() {
  if (_internal_has_float_num()) {
    _impl_.num_.float_num_ = 0;
    clear_has_num();
  }
}
inline float voidMessage::_internal_float_num() const {
  if (_internal_has_float_num()) {
    return _impl_.num_.float_num_;
  }
  return 0;
}
inline void voidMessage::_internal_set_float_num(float value) {
  if (!_internal_has_float_num()) {
    clear_num();
    set_has_float_num();
  }
  _impl_.num_.float_num_ = value;
}
inline float voidMessage::float_num() const {
  // @@protoc_insertion_point(field_get:a.voidMessage.float_num)
  return _internal_float_num();
}
inline void voidMessage::set_float_num(float value) {
  _internal_set_float_num(value);
  // @@protoc_insertion_point(field_set:a.voidMessage.float_num)
}

// string string_num = 3;
inline bool voidMessage::_internal_has_string_num() const {
  return num_case() == kStringNum;
}
inline bool voidMessage::has_string_num() const {
  return _internal_has_string_num();
}
inline void voidMessage::set_has_string_num() {
  _impl_._oneof_case_[0] = kStringNum;
}
inline void voidMessage::clear_string_num() {
  if (_internal_has_string_num()) {
    _impl_.num_.string_num_.Destroy();
    clear_has_num();
  }
}
inline const std::string& voidMessage::string_num() const {
  // @@protoc_insertion_point(field_get:a.voidMessage.string_num)
  return _internal_string_num();
}
template <typename ArgT0, typename... ArgT>
inline void voidMessage::set_string_num(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_string_num()) {
    clear_num();
    set_has_string_num();
    _impl_.num_.string_num_.InitDefault();
  }
  _impl_.num_.string_num_.Set( static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:a.voidMessage.string_num)
}
inline std::string* voidMessage::mutable_string_num() {
  std::string* _s = _internal_mutable_string_num();
  // @@protoc_insertion_point(field_mutable:a.voidMessage.string_num)
  return _s;
}
inline const std::string& voidMessage::_internal_string_num() const {
  if (_internal_has_string_num()) {
    return _impl_.num_.string_num_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void voidMessage::_internal_set_string_num(const std::string& value) {
  if (!_internal_has_string_num()) {
    clear_num();
    set_has_string_num();
    _impl_.num_.string_num_.InitDefault();
  }
  _impl_.num_.string_num_.Set(value, GetArenaForAllocation());
}
inline std::string* voidMessage::_internal_mutable_string_num() {
  if (!_internal_has_string_num()) {
    clear_num();
    set_has_string_num();
    _impl_.num_.string_num_.InitDefault();
  }
  return _impl_.num_.string_num_.Mutable(      GetArenaForAllocation());
}
inline std::string* voidMessage::release_string_num() {
  // @@protoc_insertion_point(field_release:a.voidMessage.string_num)
  if (_internal_has_string_num()) {
    clear_has_num();
    return _impl_.num_.string_num_.Release();
  } else {
    return nullptr;
  }
}
inline void voidMessage::set_allocated_string_num(std::string* string_num) {
  if (has_num()) {
    clear_num();
  }
  if (string_num != nullptr) {
    set_has_string_num();
    _impl_.num_.string_num_.InitAllocated(string_num, GetArenaForAllocation());
  }
  // @@protoc_insertion_point(field_set_allocated:a.voidMessage.string_num)
}

inline bool voidMessage::has_num() const {
  return num_case() != NUM_NOT_SET;
}
inline void voidMessage::clear_has_num() {
  _impl_._oneof_case_[0] = NUM_NOT_SET;
}
inline voidMessage::NumCase voidMessage::num_case() const {
  return voidMessage::NumCase(_impl_._oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace a

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Intmessage_2eproto
