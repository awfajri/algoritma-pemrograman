def caesar_cipher(text, shift):
  result = ""
  for char in text:
    if char.isalpha():
      if char.isupper():
        result += chr((ord(char) + shift - 65) % 26 + 65)
      else:
        result += chr((ord(char) + shift - 97) % 26 + 97)
    else:
      result += char
  return result

#Contoh penggunaan
text = "HELLO"
shift = 3
encrypted_text = caesar_cipher(text, shift)
print(encrypted_text)  # Output: KHOOR