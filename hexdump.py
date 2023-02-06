def hexdump(file):
    with open(file, 'rb') as f:
        data = f.read()
        print(f"{'Address':<10} {'0 1 2 3  4 5 6 7  8 9 A B  C D E F':>38}")
        print(f"{'-'*10} {'-'*38}")
        for i in range(0, len(data), 16):
            line = data[i:i+16]
            hex_values = ' '.join([f"{b:02X}" for b in line])
            printable = ''.join([chr(b) if 32 <= b <= 126 else '.' for b in line])
            address = f"{i:08X}"
            hex_values = ' '.join([hex_values[j:j+2] for j in range(0, len(hex_values), 2)])
            print(f"{address} {hex_values:<39} {printable}")

# Example usage:
hexdump("example.bin")
