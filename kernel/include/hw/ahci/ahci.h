#pragma once

#include "kernel/hw/pci/pci.h"
#include "libk/types.h"

#define HBA_PORT_DEV_PRESENT 0x3
#define HBA_PORT_IPM_ACTIVE 0x1
#define SATA_SIG_ATAPI 0xEB140101
#define SATA_SIG_ATA 0x00000101
#define SATA_SIG_SEMB 0xC33C0101
#define SATA_SIG_PM 0x96690101

#define HBA_PxCMD_CR 0x8000
#define HBA_PxCMD_FRE 0x0010
#define HBA_PxCMD_ST 0x0001
#define HBA_PxCMD_FR 0x4000

typedef enum ahci_port_type {
  NONE = 0,
  SATA = 1,
  SEMB = 2,
  PM = 3,
  SATAPI = 4,
} ahci_port_type_t;

typedef struct ahci_hba_port {
  u32 command_list_base;
  u32 command_list_base_upper;
  u32 fis_base_address;
  u32 fis_base_address_upper;
  u32 interrupt_status;
  u32 interrupt_enable;
  u32 cmd_sts;
  u32 rsv0;
  u32 task_file_data;
  u32 signature;
  u32 sata_status;
  u32 sata_control;
  u32 sata_error;
  u32 sata_active;
  u32 command_issue;
  u32 sata_notification;
  u32 fis_switch_control;
  u32 rsv1[11];
  u32 vendor[4];
} ahci_hba_port_t;

typedef struct ahci_hba_memory {
  u32 host_capability;
  u32 global_host_control;
  u32 interrupt_status;
  u32 ports_implemented;
  u32 version;
  u32 ccc_control;
  u32 ccc_ports;
  u32 enclosure_management_location;
  u32 enclosure_management_control;
  u32 host_capabilities_extended;
  u32 bios_handoff_ctrl_sts;
  u8 rsv0[0x74];
  u8 vendor[0x60];
  ahci_hba_port_t ports[1];
} ahci_hba_memory_t;

typedef struct ahci_hba_command_header {
  u8 command_fis_length : 5;
  u8 atapi : 1;
  u8 write : 1;
  u8 prefetchable : 1;

  u8 reset : 1;
  u8 bist : 1;
  u8 clear_busy : 1;
  u8 rsv0 : 1;
  u8 port_multiplier : 4;

  u16 prdt_length;
  u32 prdb_count;
  u32 command_table_base_address;
  u32 command_table_base_address_upper;
  u32 rsv1[4];
} ahci_hba_command_header_t;

typedef struct ahci_port {
  ahci_hba_port_t *hba_port;
  ahci_port_type_t port_type;
  u8 *buffer;
  u8 port_number;
} ahci_port_t;

void ahci_init(pci_type0_t *h);
void ahci_probe();
ahci_port_type_t ahci_check_port_type(ahci_hba_port_t *port);

void ahci_port_configure(ahci_port_t *p);
void ahci_port_start_cmd(ahci_port_t *p);
void ahci_port_stop_cmd(ahci_port_t *p);
