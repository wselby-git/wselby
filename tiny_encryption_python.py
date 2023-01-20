def encrypt(plaintext, key):
    # Create a list to store the encrypted message
    ciphertext = []
    # Loop through the plaintext and xor it with the key
    for i in range(len(plaintext)):
        ciphertext.append(plaintext[i] ^ key[i%len(key)])

    # Return the encrypted message
    return ciphertext

def decrypt(ciphertext, key):
    # Create a list to store the decrypted message
    plaintext = []
    # Loop through the ciphertext and xor it with the key
    for i in range(len(ciphertext)):
        plaintext.append(ciphertext[i] ^ key[i%len(key)])

    # Return the decrypted message
    return plaintext

# Test the encryption and decryption
plaintext = [1, 2, 3, 4]
key = [5, 6, 7, 8]

ciphertext = encrypt(plaintext, key)
decrypted_message = decrypt(ciphertext, key)

print("Plaintext:", plaintext)
print("Key:", key)
print("Ciphertext:", ciphertext)
print("Decrypted message:", decrypted_message)
