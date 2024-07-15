def GPio_init():
    ddrx_value=0
    Bit_modes=[]
    for bitNo in range (8):
        while True:
            mode=input (f"Enter mode bit for {bitNo} (in or out) : ").lower().strip()
            if mode in ("in", 'out'):
               Bit_modes.append(mode)
               break
            else:
                print('Invalid , enter (in or out) ')

    for bitNo,mode in enumerate(Bit_modes):
        if mode =="out":
            ddrx_value |=(1<<bitNo)
    
    
  # Generate the Init function
    init_function = f"""\
   void GPIO_Init() {{
    // Set DDRx register
    DDRx = 0x{ddrx_value:02X}; // 0b{ddrx_value:08b}
   }}
    """
    return init_function
    
if __name__ == "__main__":
  init_code = GPio_init()
  print("Generated GPIO Initialization Function:\n")
  print(init_code)   