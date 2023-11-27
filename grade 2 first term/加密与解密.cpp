#include <iostream>
#include <string>
#include <cctype> // 用于大小写转换
using namespace std;

// 加密函数
string vigenere_encrypt(const string &text, const string &key) {
    string encrypted_text = "";
    int text_length = text.length();
    int key_length = key.length();

    for (int i = 0; i < text_length; i++) {
        char plain_char = tolower(text[i]); // 转换为小写
        char key_char = tolower(key[i % key_length]); // 转换为小写
        char encrypted_char = ((plain_char - 'a' + key_char - 'a') % 26) + 'a';
        encrypted_text += encrypted_char;
    }

    return encrypted_text;
}

// 解密函数
string vigenere_decrypt(const string &encrypted_text, const string &key) {
    string decrypted_text = "";
    int text_length = encrypted_text.length();
    int key_length = key.length();

    for (int i = 0; i < text_length; i++) {
        char encrypted_char = tolower(encrypted_text[i]); // 转换为小写
        char key_char = tolower(key[i % key_length]); // 转换为小写
        char decrypted_char = ((encrypted_char - key_char + 26) % 26) + 'a';
        decrypted_text += decrypted_char;
    }

    return decrypted_text;
}

int main() {
    string plaintext;
    string key;
    int flag;
    cout<<"plaintext:"; cin>> plaintext;
    cout<<"key:"; cin>>key;
    cout<<"1:加密 2:解密\n"<<"输入1或2:"; cin>> flag;

    if(flag==1){
    // 加密
        string encrypted_text = vigenere_encrypt(plaintext, key);
        cout << "Encrypted Text: " << encrypted_text << endl;
    }
    // 解密
    else if(flag==2){
        string decrypted_text = vigenere_decrypt(plaintext, key);
        cout << "Decrypted Text: " << decrypted_text << endl;
    }
    
    return 0;
}
