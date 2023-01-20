//Tiny Encryption Algorithm (TEA) is a symmetric block cipher used to encrypt and decrypt data.

//Function to perform encryption using TEA
fun TEAEncrypt(key: IntArray, data: IntArray): IntArray {
    //Check the length of the data
    if (data.size != 2) {
        throw Exception("Data must be two 32-bit words long.")
    }
    //Check the length of the key
    if (key.size != 4) {
        throw Exception("Key must be four 32-bit words long.")
    }
    //Initialize sum to 0
    var sum = 0
    //Initialize delta to 0x9E3779B9
    val delta = 0x9E3779B9
    //Loop for 32 rounds
    for (i in 0 until 32) {
        //Add sum to data[0]
        data[0] += (data[1] shl 4 xor data[1] ushr 5) + data[1] xor sum + key[sum and 3]
        //Rotate sum by 11
        sum += delta
        //Add sum to data[1]
        data[1] += (data[0] shl 4 xor data[0] ushr 5) + data[0] xor sum + key[sum ushr 11 and 3]
    }
    //Return the encrypted data
    return data
}

//Function to perform decryption using TEA
fun TEADecrypt(key: IntArray, data: IntArray): IntArray {
    //Check the length of the data
    if (data.size != 2) {
        throw Exception("Data must be two 32-bit words long.")
    }
    //Check the length of the key
    if (key.size != 4) {
        throw Exception("Key must be four 32-bit words long.")
    }
    //Initialize sum to 0xC6EF3720
    var sum = 0xC6EF3720
    //Initialize delta to 0x9E3779B9
    val delta = 0x9E3779B9
    //Loop for 32 rounds
    for (i in 0 until 32) {
        //Subtract sum from data[1]
        data[1] -= (data[0] shl 4 xor data[0] ushr 5) + data[0] xor sum + key[sum ushr 11 and 3]
        //Rotate sum by 11
        sum -= delta
        //Subtract sum from data[0]
        data[0] -= (data[1] shl 4 xor data[1] ushr 5) + data[1] xor sum + key[sum and 3]
    }
    //Return the decrypted data
    return data
}

//Key
val key = intArrayOf(0x12345678, 0x9ABCDEF0, 0xCAFEBABE, 0xFEDC9876)

//Data
val data = intArrayOf(0xABCDEF12, 0x34567890)

//Encrypt the data
val encryptedData = TEAEncrypt(key, data)

//Decrypt the encrypted data
val decryptedData = TEADecrypt(key, encryptedData)

//Print the encrypted data
println("Encrypted data: ${encryptedData[0].toString(16)}, ${encryptedData[1].toString(16)}")

//Print the decrypted data
println("Decrypted data: ${decryptedData[0].toString(16)}, ${decryptedData[1].toString(16)}")
