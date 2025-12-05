

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl 
using RTI Code Generator (rtiddsgen) version 4.6.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 

#ifndef dds_c_log_infrastructure_h
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#include "osapi/osapi_atomic.h"
#else
#include "ndds_standalone_type.h"
#endif

#include "ShapeType.h"

#ifndef NDDS_STANDALONE_TYPE
#include "ShapeTypePlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *ShapeFillKindTYPENAME = "ShapeFillKind";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * ShapeFillKind_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member ShapeFillKind_g_tc_members[4]=
    {

        {
            (char *)"SOLID_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            SOLID_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"TRANSPARENT_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            TRANSPARENT_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"HORIZONTAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            HORIZONTAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"VERTICAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            VERTICAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeFillKind_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeFillKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ShapeFillKind_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeFillKind*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &ShapeFillKind_g_tc;
    }

    ShapeFillKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    ShapeFillKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ShapeFillKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

    ShapeFillKind_g_tc._data._sampleAccessInfo =
    ShapeFillKind_get_sample_access_info();
    ShapeFillKind_g_tc._data._typePlugin =
    ShapeFillKind_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &ShapeFillKind_g_tc;
}

#define TSeq ShapeFillKindSeq
#define T ShapeFillKind
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeFillKind_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeFillKind_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeFillKindSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeFillKindSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeFillKind_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeFillKind_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static RTIXCdrMemberAccessInfo ShapeFillKind_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeFillKind_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &ShapeFillKind_g_sampleAccessInfo;
    }

    ShapeFillKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    ShapeFillKind_g_sampleAccessInfo.memberAccessInfos = 
    ShapeFillKind_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeFillKind);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            ShapeFillKind_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            ShapeFillKind_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeFillKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeFillKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeFillKind_get_member_value_pointer;

    ShapeFillKind_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &ShapeFillKind_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *ShapeFillKind_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeFillKind_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeFillKind_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeFillKind_finalize_w_return,
        NULL,
        NULL
    };

    return &ShapeFillKind_g_typePlugin;
}
#endif

RTIBool ShapeFillKind_initialize(
    ShapeFillKind* sample)
{

    *sample = SOLID_FILL;
    return RTI_TRUE;
}
RTIBool ShapeFillKind_initialize_w_params(
    ShapeFillKind *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = SOLID_FILL;
    return RTI_TRUE;
}
RTIBool ShapeFillKind_initialize_ex(
    ShapeFillKind *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeFillKind_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool ShapeFillKind_finalize_w_return(
    ShapeFillKind* sample)
{
    if (sample) {} /* To avoid warnings */

    return RTI_TRUE;
}

void ShapeFillKind_finalize(
    ShapeFillKind* sample)
{  
    if (sample==NULL) {
        return;
    }
}

void ShapeFillKind_finalize_ex(
    ShapeFillKind *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeFillKind_finalize_w_params(
        sample,
        &deallocParams);
}

void ShapeFillKind_finalize_w_params(
    ShapeFillKind *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void ShapeFillKind_finalize_optional_members(
    ShapeFillKind* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ShapeFillKind_copy(
    ShapeFillKind* dst,
    const ShapeFillKind* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeFillKind' sequence class.
*/
#define T ShapeFillKind
#define TSeq ShapeFillKindSeq

#define T_initialize_w_params ShapeFillKind_initialize_w_params

#define T_finalize_w_params   ShapeFillKind_finalize_w_params
#define T_copy       ShapeFillKind_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *ShapeTypeTYPENAME = "ShapeType";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * ShapeType_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode ShapeType_g_tc_color_string = DDS_INITIALIZE_STRING_TYPECODE((128L));

    static DDS_TypeCode_Member ShapeType_g_tc_members[4]=
    {

        {
            (char *)"color",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"x",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"y",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"shapesize",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeType_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeType", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ShapeType_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeType*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &ShapeType_g_tc;
    }

    ShapeType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ShapeType_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)&ShapeType_g_tc_color_string;
    ShapeType_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    ShapeType_g_tc_members[2]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    ShapeType_g_tc_members[3]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_long_w_new;

    /* Initialize the values for member annotations. */
    ShapeType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    ShapeType_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
    ShapeType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    ShapeType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
    ShapeType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
    ShapeType_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeType_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
    ShapeType_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
    ShapeType_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeType_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    ShapeType_g_tc._data._sampleAccessInfo =
    ShapeType_get_sample_access_info();
    ShapeType_g_tc._data._typePlugin =
    ShapeType_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &ShapeType_g_tc;
}

#define TSeq ShapeTypeSeq
#define T ShapeType
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeType_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeType_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeTypeSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeTypeSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeType_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeType_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    ShapeType *sample;

    static RTIXCdrMemberAccessInfo ShapeType_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeType_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &ShapeType_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ShapeType);
    if (sample == NULL) {
        return NULL;
    }

    ShapeType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->color - (char *)sample);

    ShapeType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->x - (char *)sample);

    ShapeType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->y - (char *)sample);

    ShapeType_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->shapesize - (char *)sample);

    ShapeType_g_sampleAccessInfo.memberAccessInfos = 
    ShapeType_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeType);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            ShapeType_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            ShapeType_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeType_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeType_get_member_value_pointer;

    ShapeType_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &ShapeType_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *ShapeType_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeType_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeType_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeType_finalize_w_return,
        NULL,
        NULL
    };

    return &ShapeType_g_typePlugin;
}
#endif

RTIBool ShapeType_initialize(
    ShapeType* sample)
{
    return ShapeType_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool ShapeType_initialize_w_params(
    ShapeType *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->color = DDS_String_alloc((128L));
        if (sample->color != NULL) {
            RTIOsapiUtility_unusedReturnValue(
                RTICdrType_copyStringEx(
                    &sample->color,
                    "",
                    (128L),
                    RTI_FALSE),
                    RTIBool);
        }
        if (sample->color == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->color != NULL) {
            RTIOsapiUtility_unusedReturnValue(
                RTICdrType_copyStringEx(
                    &sample->color,
                    "",
                    (128L),
                    RTI_FALSE),
                    RTIBool);
            if (sample->color == NULL) {
                return RTI_FALSE;
            }
        }
    }

    sample->x = 0;

    sample->y = 0;

    sample->shapesize = 0;

    return RTI_TRUE;
}
RTIBool ShapeType_initialize_ex(
    ShapeType *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeType_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool ShapeType_finalize_w_return(
    ShapeType* sample)
{
    ShapeType_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void ShapeType_finalize(
    ShapeType* sample)
{  
    ShapeType_finalize_ex(
        sample, 
        RTI_TRUE);
}

void ShapeType_finalize_ex(
    ShapeType *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeType_finalize_w_params(
        sample,
        &deallocParams);
}

void ShapeType_finalize_w_params(
    ShapeType *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->color != NULL) {
        DDS_String_free(sample->color);
        sample->color=NULL;

    }

}

void ShapeType_finalize_optional_members(
    ShapeType* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ShapeType_copy(
    ShapeType* dst,
    const ShapeType* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->color
            ,
            src->color, 
            (128L) + 1,
            RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->x, 
            &src->x)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->y, 
            &src->y)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->shapesize, 
            &src->shapesize)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeType' sequence class.
*/
#define T ShapeType
#define TSeq ShapeTypeSeq

#define T_initialize_w_params ShapeType_initialize_w_params

#define T_finalize_w_params   ShapeType_finalize_w_params
#define T_copy       ShapeType_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *ShapeTypeExtendedTYPENAME = "ShapeTypeExtended";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * ShapeTypeExtended_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member ShapeTypeExtended_g_tc_members[2]=
    {

        {
            (char *)"fillKind",/* Member name */
            {
                4,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"angle",/* Member name */
            {
                5,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeTypeExtended_g_tc =
    {{
            DDS_TK_VALUE, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeTypeExtended", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            ShapeTypeExtended_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeTypeExtended*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &ShapeTypeExtended_g_tc;
    }

    ShapeTypeExtended_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ShapeTypeExtended_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)ShapeFillKind_get_typecode();
    ShapeTypeExtended_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    ShapeTypeExtended_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ShapeTypeExtended_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;
    ShapeTypeExtended_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    ShapeTypeExtended_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    ShapeTypeExtended_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    ShapeTypeExtended_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    ShapeTypeExtended_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    ShapeTypeExtended_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    ShapeTypeExtended_g_tc._data._typeCode = (RTICdrTypeCode *)ShapeType_get_typecode(); /* Base class */

    ShapeTypeExtended_g_tc._data._sampleAccessInfo =
    ShapeTypeExtended_get_sample_access_info();
    ShapeTypeExtended_g_tc._data._typePlugin =
    ShapeTypeExtended_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &ShapeTypeExtended_g_tc;
}

#define TSeq ShapeTypeExtendedSeq
#define T ShapeTypeExtended
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeTypeExtended_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeTypeExtended_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeTypeExtendedSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeTypeExtendedSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeTypeExtended_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeTypeExtended_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    ShapeTypeExtended *sample;

    static RTIXCdrMemberAccessInfo ShapeTypeExtended_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeTypeExtended_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &ShapeTypeExtended_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ShapeTypeExtended);
    if (sample == NULL) {
        return NULL;
    }

    ShapeTypeExtended_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->fillKind - (char *)sample);

    ShapeTypeExtended_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->angle - (char *)sample);

    ShapeTypeExtended_g_sampleAccessInfo.memberAccessInfos = 
    ShapeTypeExtended_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeTypeExtended);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            ShapeTypeExtended_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            ShapeTypeExtended_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeTypeExtended_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeTypeExtended_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeTypeExtended_get_member_value_pointer;

    ShapeTypeExtended_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &ShapeTypeExtended_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *ShapeTypeExtended_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeTypeExtended_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeTypeExtended_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeTypeExtended_finalize_w_return,
        NULL,
        NULL
    };

    return &ShapeTypeExtended_g_typePlugin;
}
#endif

RTIBool ShapeTypeExtended_initialize(
    ShapeTypeExtended* sample)
{
    return ShapeTypeExtended_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool ShapeTypeExtended_initialize_w_params(
    ShapeTypeExtended *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    if (!ShapeType_initialize_w_params(
        (ShapeType*) sample,
        allocParams)) {
        return RTI_FALSE;
    }

    sample->fillKind = SOLID_FILL;
    sample->angle = 0.0f;

    return RTI_TRUE;
}
RTIBool ShapeTypeExtended_initialize_ex(
    ShapeTypeExtended *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeTypeExtended_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool ShapeTypeExtended_finalize_w_return(
    ShapeTypeExtended* sample)
{
    ShapeTypeExtended_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void ShapeTypeExtended_finalize(
    ShapeTypeExtended* sample)
{  
    ShapeTypeExtended_finalize_ex(
        sample, 
        RTI_TRUE);
}

void ShapeTypeExtended_finalize_ex(
    ShapeTypeExtended *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeTypeExtended_finalize_w_params(
        sample,
        &deallocParams);
}

void ShapeTypeExtended_finalize_w_params(
    ShapeTypeExtended *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    ShapeType_finalize_w_params(
        (ShapeType*) sample,
        deallocParams);

    ShapeFillKind_finalize_w_params(
        &sample->fillKind,
        deallocParams);

}

void ShapeTypeExtended_finalize_optional_members(
    ShapeTypeExtended* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    ShapeType_finalize_optional_members((ShapeType*)sample,deletePointers);

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ShapeTypeExtended_copy(
    ShapeTypeExtended* dst,
    const ShapeTypeExtended* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if(!ShapeType_copy(
            (ShapeType*)dst,
            (const ShapeType*)src)) {
            return RTI_FALSE;
        }

        if (!ShapeFillKind_copy(
            &dst->fillKind,
            (const ShapeFillKind*)&src->fillKind)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyFloat (
            &dst->angle, 
            &src->angle)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeTypeExtended' sequence class.
*/
#define T ShapeTypeExtended
#define TSeq ShapeTypeExtendedSeq

#define T_initialize_w_params ShapeTypeExtended_initialize_w_params

#define T_finalize_w_params   ShapeTypeExtended_finalize_w_params
#define T_copy       ShapeTypeExtended_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *ShapeTypeExtended3DTYPENAME = "ShapeTypeExtended3D";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * ShapeTypeExtended3D_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member ShapeTypeExtended3D_g_tc_members[1]=
    {

        {
            (char *)"z",/* Member name */
            {
                6,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeTypeExtended3D_g_tc =
    {{
            DDS_TK_VALUE, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeTypeExtended3D", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            ShapeTypeExtended3D_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeTypeExtended3D*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &ShapeTypeExtended3D_g_tc;
    }

    ShapeTypeExtended3D_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ShapeTypeExtended3D_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_long_w_new;

    /* Initialize the values for member annotations. */
    ShapeTypeExtended3D_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeTypeExtended3D_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    ShapeTypeExtended3D_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeTypeExtended3D_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeTypeExtended3D_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeTypeExtended3D_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    ShapeTypeExtended3D_g_tc._data._typeCode = (RTICdrTypeCode *)ShapeTypeExtended_get_typecode(); /* Base class */

    ShapeTypeExtended3D_g_tc._data._sampleAccessInfo =
    ShapeTypeExtended3D_get_sample_access_info();
    ShapeTypeExtended3D_g_tc._data._typePlugin =
    ShapeTypeExtended3D_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &ShapeTypeExtended3D_g_tc;
}

#define TSeq ShapeTypeExtended3DSeq
#define T ShapeTypeExtended3D
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeTypeExtended3D_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeTypeExtended3D_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeTypeExtended3DSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeTypeExtended3DSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeTypeExtended3D_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeTypeExtended3D_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    ShapeTypeExtended3D *sample;

    static RTIXCdrMemberAccessInfo ShapeTypeExtended3D_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeTypeExtended3D_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &ShapeTypeExtended3D_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ShapeTypeExtended3D);
    if (sample == NULL) {
        return NULL;
    }

    ShapeTypeExtended3D_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->z - (char *)sample);

    ShapeTypeExtended3D_g_sampleAccessInfo.memberAccessInfos = 
    ShapeTypeExtended3D_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeTypeExtended3D);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            ShapeTypeExtended3D_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            ShapeTypeExtended3D_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeTypeExtended3D_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeTypeExtended3D_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeTypeExtended3D_get_member_value_pointer;

    ShapeTypeExtended3D_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &ShapeTypeExtended3D_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *ShapeTypeExtended3D_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeTypeExtended3D_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeTypeExtended3D_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeTypeExtended3D_finalize_w_return,
        NULL,
        NULL
    };

    return &ShapeTypeExtended3D_g_typePlugin;
}
#endif

RTIBool ShapeTypeExtended3D_initialize(
    ShapeTypeExtended3D* sample)
{
    return ShapeTypeExtended3D_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool ShapeTypeExtended3D_initialize_w_params(
    ShapeTypeExtended3D *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    if (!ShapeTypeExtended_initialize_w_params(
        (ShapeTypeExtended*) sample,
        allocParams)) {
        return RTI_FALSE;
    }

    sample->z = 0;

    return RTI_TRUE;
}
RTIBool ShapeTypeExtended3D_initialize_ex(
    ShapeTypeExtended3D *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeTypeExtended3D_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool ShapeTypeExtended3D_finalize_w_return(
    ShapeTypeExtended3D* sample)
{
    ShapeTypeExtended3D_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void ShapeTypeExtended3D_finalize(
    ShapeTypeExtended3D* sample)
{  
    ShapeTypeExtended3D_finalize_ex(
        sample, 
        RTI_TRUE);
}

void ShapeTypeExtended3D_finalize_ex(
    ShapeTypeExtended3D *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeTypeExtended3D_finalize_w_params(
        sample,
        &deallocParams);
}

void ShapeTypeExtended3D_finalize_w_params(
    ShapeTypeExtended3D *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    ShapeTypeExtended_finalize_w_params(
        (ShapeTypeExtended*) sample,
        deallocParams);

}

void ShapeTypeExtended3D_finalize_optional_members(
    ShapeTypeExtended3D* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    ShapeTypeExtended_finalize_optional_members((ShapeTypeExtended*)sample,deletePointers);

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ShapeTypeExtended3D_copy(
    ShapeTypeExtended3D* dst,
    const ShapeTypeExtended3D* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if(!ShapeTypeExtended_copy(
            (ShapeTypeExtended*)dst,
            (const ShapeTypeExtended*)src)) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->z, 
            &src->z)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeTypeExtended3D' sequence class.
*/
#define T ShapeTypeExtended3D
#define TSeq ShapeTypeExtended3DSeq

#define T_initialize_w_params ShapeTypeExtended3D_initialize_w_params

#define T_finalize_w_params   ShapeTypeExtended3D_finalize_w_params
#define T_copy       ShapeTypeExtended3D_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code< ShapeType>::get() 
        {
            return (const RTIXCdrTypeCode *) ShapeType_get_typecode();
        }

        const RTIXCdrTypeCode * type_code< ShapeTypeExtended>::get() 
        {
            return (const RTIXCdrTypeCode *) ShapeTypeExtended_get_typecode();
        }

        const RTIXCdrTypeCode * type_code< ShapeTypeExtended3D>::get() 
        {
            return (const RTIXCdrTypeCode *) ShapeTypeExtended3D_get_typecode();
        }

    } 
}
#endif
