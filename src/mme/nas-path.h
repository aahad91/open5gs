/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef NAS_PATH_H
#define NAS_PATH_H

#include "mme-context.h"

#ifdef __cplusplus
extern "C" {
#endif

int nas_send_to_enb(mme_ue_t *mme_ue, ogs_pkbuf_t *pkbuf);
int nas_send_emm_to_esm(
    mme_ue_t *mme_ue, ogs_nas_esm_message_container_t *esm_message_container);
int nas_send_to_downlink_nas_transport(mme_ue_t *mme_ue, ogs_pkbuf_t *pkbuf);

int nas_send_attach_accept(mme_ue_t *mme_ue);
void nas_send_attach_reject(mme_ue_t *mme_ue,
    ogs_nas_emm_cause_t emm_cause, ogs_nas_esm_cause_t esm_cause);

int nas_send_identity_request(mme_ue_t *mme_ue);

int nas_send_authentication_request(
        mme_ue_t *mme_ue, ogs_diam_e_utran_vector_t *e_utran_vector);
int nas_send_authentication_reject(mme_ue_t *mme_ue);

int nas_send_security_mode_command(mme_ue_t *mme_ue);

void nas_send_detach_accept(mme_ue_t *mme_ue);

int nas_send_pdn_connectivity_reject(
    mme_sess_t *sess, ogs_nas_esm_cause_t esm_cause);
int nas_send_esm_information_request(mme_bearer_t *bearer);
int nas_send_activate_default_bearer_context_request(mme_bearer_t *bearer);
int nas_send_activate_dedicated_bearer_context_request(mme_bearer_t *bearer);
int nas_send_activate_all_dedicated_bearers(mme_bearer_t *default_bearer);
int nas_send_modify_bearer_context_request(
        mme_bearer_t *bearer, int qos_presence, int tft_presence);
int nas_send_deactivate_bearer_context_request(mme_bearer_t *bearer);

int nas_send_tau_accept(mme_ue_t *mme_ue, S1AP_ProcedureCode_t procedureCode);
int nas_send_tau_reject(mme_ue_t *mme_ue, ogs_nas_esm_cause_t emm_cause);

void nas_send_service_reject(mme_ue_t *mme_ue, ogs_nas_emm_cause_t emm_cause);

int nas_send_cs_service_notification(mme_ue_t *mme_ue);
int nas_send_downlink_nas_transport(
        mme_ue_t *mme_ue, uint8_t *buffer, uint8_t length);

#ifdef __cplusplus
}
#endif

#endif /* NAS_PATH_H */
