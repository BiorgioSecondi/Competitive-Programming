#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

// Funzione per decriptare con Vigenère
string decriptaVigenere(const string& testoCriptato, const string& chiave) {
    string testoDecriptato = "";
    int lunghezzaChiave = chiave.length();
    
    for (size_t i = 0; i < testoCriptato.length(); i++) {
        char carattereCriptato = testoCriptato[i];
        char carattereChiave = chiave[i % lunghezzaChiave];
        
        if (isalpha(carattereCriptato)) {
            bool maiuscolo = isupper(carattereCriptato);
            char base = maiuscolo ? 'A' : 'a';
            
            // Decriptazione Vigenère
            char carattereDecriptato = ((carattereCriptato - base) - (toupper(carattereChiave) - 'A') + 26) % 26 + base;
            testoDecriptato += carattereDecriptato;
        } else {
            // Mantieni caratteri non alfabetici
            testoDecriptato += carattereCriptato;
        }
    }
    
    return testoDecriptato;
}

// Funzione per calcolare l'indice di coincidenza (IC)
double calcolaIndiceCoincidenza(const string& testo) {
    vector<int> frequenze(26, 0);
    int totaleLettere = 0;
    
    // Conta le frequenze delle lettere
    for (char c : testo) {
        if (isalpha(c)) {
            frequenze[toupper(c) - 'A']++;
            totaleLettere++;
        }
    }
    
    if (totaleLettere == 0) return 0.0;
    
    // Calcola l'indice di coincidenza
    double ic = 0.0;
    for (int freq : frequenze) {
        ic += (freq * (freq - 1));
    }
    ic /= (totaleLettere * (totaleLettere - 1));
    
    return ic;
}

// Funzione per generare tutte le possibili chiavi di lunghezza data
vector<string> generaChiavi(int lunghezzaChiave, int maxChiavi = 1000) {
    vector<string> chiavi;
    string chiave(lunghezzaChiave, 'A');
    
    // Funzione ricorsiva per generare chiavi
    function<void(int)> genera = [&](int pos) {
        if (pos == lunghezzaChiave || chiavi.size() >= maxChiavi) {
            if (chiavi.size() < maxChiavi) {
                chiavi.push_back(chiave);
            }
            return;
        }
        
        for (char c = 'A'; c <= 'Z'; c++) {
            if (chiavi.size() >= maxChiavi) break;
            chiave[pos] = c;
            genera(pos + 1);
        }
    };
    
    genera(0);
    return chiavi;
}

// Funzione per rimuovere caratteri non alfabetici (per analisi)
string filtraAlfabetico(const string& testo) {
    string risultato = "";
    for (char c : testo) {
        if (isalpha(c)) {
            risultato += toupper(c);
        }
    }
    return risultato;
}

// Attacco brute force migliorato
void attaccoBruteForceMigliorato(const string& testoCriptato) {
    cout << "=== ATTACCO BRUTE FORCE AL CIFRARIO DI VIGENÈRE ===" << endl;
    cout << "Testo criptato: " << testoCriptato << endl;
    cout << "===================================================" << endl;
    
    const int MAX_LUNGHEZZA_CHIAVE = 20;
    const double SOGLIA_IC = 0.06; // Soglia per italiano/inglese
    
    vector<pair<double, pair<string, string>>> risultati; // IC, (chiave, testo decriptato)
    
    // Prova diverse lunghezze della chiave
    for (int lunghezzaChiave = 1; lunghezzaChiave <= MAX_LUNGHEZZA_CHIAVE; lunghezzaChiave++) {
        cout << "Testando chiavi di lunghezza " << lunghezzaChiave << "..." << endl;
        
        vector<string> chiavi = generaChiavi(lunghezzaChiave, 100000000); // Limita a 1000 chiavi per lunghezza
        
        for (const string& chiave : chiavi) {
            string testoDecriptato = decriptaVigenere(testoCriptato, chiave);
            string testoFiltrato = filtraAlfabetico(testoDecriptato);
            
            if (testoFiltrato.length() > 0) {
                double ic = calcolaIndiceCoincidenza(testoFiltrato);
                
                // Se l'IC è sopra la soglia, salva il risultato
                if (ic >= SOGLIA_IC) {
                    risultati.push_back({ic, {chiave, testoDecriptato}});
                }
            }
        }
    }
    
    // Ordina i risultati per IC (discendente)
    sort(risultati.begin(), risultati.end(), 
         [](const pair<double, pair<string, string>>& a, const pair<double, pair<string, string>>& b) {
             return a.first > b.first;
         });
    
    // Stampa i risultati migliori
    cout << "\n=== RISULTATI MIGLIORI ===" << endl;
    int risultatiDaMostrare = min(10, (int)risultati.size());
    
    for (int i = 0; i < risultatiDaMostrare; i++) {
        cout << "Risultato " << (i + 1) << ":" << endl;
        cout << "  Chiave: " << risultati[i].second.first << endl;
        cout << "  IC: " << risultati[i].first << endl;
        cout << "  Testo decriptato: " << risultati[i].second.second << endl;
        cout << endl;
    }
    
    if (risultati.empty()) {
        cout << "Nessun risultato promettente trovato. Prova ad aumentare la lunghezza massima della chiave." << endl;
    }
}

// Attacco brute force semplice (tutte le chiavi di lunghezza 1-3)
void attaccoBruteForceSemplice(const string& testoCriptato) {
    cout << "=== ATTACCO BRUTE FORCE SEMPLICE ===" << endl;
    
    for (int lunghezza = 1; lunghezza <= 3; lunghezza++) {
        cout << "\nChiavi di lunghezza " << lunghezza << ":" << endl;
        vector<string> chiavi = generaChiavi(lunghezza, 50); // Solo 50 chiavi per dimostrazione
        
        for (const string& chiave : chiavi) {
            string decriptato = decriptaVigenere(testoCriptato, chiave);
            cout << "Chiave: '" << chiave << "' -> " << decriptato << endl;
        }
    }
}

int main() {
    string testoCriptato;
    
    cout << "Inserisci il testo criptato con Vigenère: ";
    getline(cin, testoCriptato);
    
    if (testoCriptato.empty()) {
        // Esempio di test
        testoCriptato = "Lxfopv ef Rnhl";
        cout << "Usando testo di esempio: " << testoCriptato << endl;
    }
    
    cout << "\nScegli il tipo di attacco:" << endl;
    cout << "1. Attacco semplice (chiavi corte)" << endl;
    cout << "2. Attacco migliorato (con analisi IC)" << endl;
    cout << "Scelta: ";
    
    int scelta;
    cin >> scelta;
    cin.ignore(); // Pulisce il buffer
    
    if (scelta == 1) {
        attaccoBruteForceSemplice(testoCriptato);
    } else {
        attaccoBruteForceMigliorato(testoCriptato);
    }
    
    return 0;
}