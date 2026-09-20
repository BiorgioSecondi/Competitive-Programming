#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

// Funzione per decifrare un testo con la chiave data
string decryptVigenere(const string& ciphertext, const string& key) {
    string plaintext;
    int keyLen = key.length();
    
    for (size_t i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            char c = toupper(ciphertext[i]);
            char k = toupper(key[i % keyLen]);
            
            // Decifrazione: P = (C - K + 26) % 26
            char p = ((c - 'A') - (k - 'A') + 26) % 26 + 'A';
            plaintext += p;
        } else {
            plaintext += ciphertext[i];
        }
    }
    
    return plaintext;
}

// Funzione per verificare se il crib appare nel testo decifrato
bool containsCrib(const string& text, const string& crib) {
    string upperText = text;
    string upperCrib = crib;
    
    // Converti in maiuscolo per confronto case-insensitive
    for (char& c : upperText) c = toupper(c);
    for (char& c : upperCrib) c = toupper(c);
    
    return upperText.find(upperCrib) != string::npos;
}

// Funzione per generare tutte le possibili chiavi di lunghezza data
vector<string> generateKeys(int keyLength) {
    vector<string> keys;
    string key(keyLength, 'A');
    
    // Funzione ricorsiva per generare chiavi
    function<void(int)> generate = [&](int pos) {
        if (pos == keyLength) {
            keys.push_back(key);
            return;
        }
        
        for (char c = 'A'; c <= 'Z'; c++) {
            key[pos] = c;
            generate(pos + 1);
        }
    };
    
    generate(0);
    return keys;
}

// Attacco bruteforce con crib
void bruteForceWithCrib(const string& ciphertext, const string& crib, int maxKeyLength = 8) {
    cout << "Avvio attacco bruteforce con crib: '" << crib << "'" << endl;
    cout << "Testo cifrato: '" << ciphertext << "'" << endl;
    cout << "Lunghezza massima chiave: " << maxKeyLength << endl;
    cout << "----------------------------------------" << endl;
    
    int solutionsFound = 0;
    
    // Prova tutte le lunghezze di chiave da 1 a maxKeyLength
    for (int keyLen = 1; keyLen <= maxKeyLength; keyLen++) {
        cout << "Testando chiavi di lunghezza " << keyLen << "..." << endl;
        
        vector<string> keys = generateKeys(keyLen);
        
        for (const string& key : keys) {
            string plaintext = decryptVigenere(ciphertext, key);
            
            if (containsCrib(plaintext, crib)) {
                solutionsFound++;
                cout << "\n*** SOLUZIONE TROVATA ***" << endl;
                cout << "Chiave: " << key << endl;
                cout << "Testo decifrato: " << plaintext << endl;
                cout << "----------------------------------------" << endl;
            }
        }
    }
    
    if (solutionsFound == 0) {
        cout << "\nNessuna soluzione trovata con i parametri attuali." << endl;
        cout << "Prova ad aumentare la lunghezza massima della chiave." << endl;
    } else {
        cout << "\nTrovate " << solutionsFound << " soluzioni possibili." << endl;
    }
}

// Versione ottimizzata che cerca solo nelle posizioni possibili
void optimizedBruteForce(const string& ciphertext, const string& crib, int maxKeyLength = 8) {
    cout << "\nAvvio attacco ottimizzato..." << endl;
    
    string upperCipher = ciphertext;
    string upperCrib = crib;
    
    // Converti in maiuscolo
    for (char& c : upperCipher) c = toupper(c);
    for (char& c : upperCrib) c = toupper(c);
    
    int cribLen = crib.length();
    int textLen = ciphertext.length();
    int solutionsFound = 0;
    
    for (int keyLen = 1; keyLen <= maxKeyLength; keyLen++) {
        cout << "Testando chiavi di lunghezza " << keyLen << "..." << endl;
        
        // Per ogni possibile posizione del crib nel testo cifrato
        for (int pos = 0; pos <= textLen - cribLen; pos++) {
            // Deriva una chiave potenziale dal crib in questa posizione
            string potentialKey(keyLen, '?');
            bool validKey = true;
            
            for (int i = 0; i < cribLen && validKey; i++) {
                int keyIndex = (pos + i) % keyLen;
                char c = upperCipher[pos + i];
                char p = upperCrib[i];
                
                // Calcola il carattere della chiave: K = (C - P + 26) % 26
                char k = ((c - 'A') - (p - 'A') + 26) % 26 + 'A';
                
                // Se questa posizione della chiave è già stata assegnata, verifica che corrisponda
                if (potentialKey[keyIndex] == '?') {
                    potentialKey[keyIndex] = k;
                } else if (potentialKey[keyIndex] != k) {
                    validKey = false;
                }
            }
            
            // Se la chiave è valida, verifica la decifrazione completa
            if (validKey) {
                // Sostituisci i '?' con 'A' (valore default)
                for (char& k : potentialKey) {
                    if (k == '?') k = 'A';
                }
                
                string plaintext = decryptVigenere(ciphertext, potentialKey);
                
                if (containsCrib(plaintext, crib)) {
                    solutionsFound++;
                    cout << "\n*** SOLUZIONE TROVATA ***" << endl;
                    cout << "Chiave: " << potentialKey << " (posizione crib: " << pos << ")" << endl;
                    cout << "Testo decifrato: " << plaintext << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
        }
    }
    
    if (solutionsFound == 0) {
        cout << "Nessuna soluzione trovata." << endl;
    }
}

int main() {
    string ciphertext, crib;
    int maxKeyLength;
    
    cout << "=== Attacco Brute Force a Vigenere con Crib ===" << endl;
    
    // Input del testo cifrato
    cout << "Inserisci il testo cifrato: ";
    getline(cin, ciphertext);
    
    // Input del crib
    cout << "Inserisci il crib (testo noto): ";
    getline(cin, crib);
    
    // Input della lunghezza massima della chiave
    cout << "Inserisci la lunghezza massima della chiave da testare: ";
    cin >> maxKeyLength;
    
    cout << endl;
    
    // Scegli il metodo di attacco
    int choice;
    cout << "Scegli il metodo di attacco:" << endl;
    cout << "1. Brute force completo" << endl;
    cout << "2. Brute force ottimizzato" << endl;
    cout << "Scelta: ";
    cin >> choice;
    
    if (choice == 1) {
        bruteForceWithCrib(ciphertext, crib, maxKeyLength);
    } else {
        optimizedBruteForce(ciphertext, crib, maxKeyLength);
    }
    
    return 0;
}