/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "Seader"
 * 	found in "seader.asn1"
 * 	`asn1c -D ./lib/asn1 -no-gen-example -pdu=all`
 */

#ifndef	_SamResponse_H_
#define	_SamResponse_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SamResponse */
typedef OCTET_STRING_t	 SamResponse_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SamResponse;
asn_struct_free_f SamResponse_free;
asn_struct_print_f SamResponse_print;
asn_constr_check_f SamResponse_constraint;
ber_type_decoder_f SamResponse_decode_ber;
der_type_encoder_f SamResponse_encode_der;
xer_type_decoder_f SamResponse_decode_xer;
xer_type_encoder_f SamResponse_encode_xer;
oer_type_decoder_f SamResponse_decode_oer;
oer_type_encoder_f SamResponse_encode_oer;
per_type_decoder_f SamResponse_decode_uper;
per_type_encoder_f SamResponse_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SamResponse_H_ */
#include <asn_internal.h>
