def fattoriali_mod_p(p):
    if p < 4:
        print("p deve essere almeno 4")
        return
    
    fatt = 1
    for a in range(1, p - 2):  # fino a p-3 incluso
        fatt = (fatt * a) % p
        print(a, fatt)

# Esempio di utilizzo
p = int(input("Inserisci un numero primo p: "))
fattoriali_mod_p(p)