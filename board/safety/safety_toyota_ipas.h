
static int toyota_ipas_fwd_hook(int bus_num, CAN_FIFOMailBox_TypeDef *to_fwd) {
  if (bus_num == 0) {
    return 2;
  }
  if (bus_num == 2) {
    return 0;
  }
  return -1;
}

const safety_hooks toyota_ipas_hooks = {
  .init = alloutput_init,
  .rx = default_rx_hook,
  .tx = alloutput_tx_hook,
  .tx_lin = nooutput_tx_lin_hook,
  .fwd = toyota_ipas_fwd_hook,
};
