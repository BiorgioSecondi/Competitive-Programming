import re
import pandas as pd
from PyPDF2 import PdfReader

pdf_file = "Punteggi-I-e-II-prova-scritta-SN-2025-1.pdf"

# Legge il testo dal PDF
reader = PdfReader(pdf_file)
text = ""
for page in reader.pages:
    text += page.extract_text() + "\n"

# Regex per linee tipo: 198 6,81 9,30 8,06
pattern = re.compile(r"(\d+)\s+(\d+,\d+)\s+(\d+,\d+)\s+(\d+,\d+)")

normalisti = [
    184, #matilde iannaccone
    222, #loek van der zijde
    123, #roger rama
    143, #alessandro d'orazio
    20,   #leonardo licciardi
    94 #samuele rozzoni
]

records = []
for match in pattern.finditer(text):
    codice = match.group(1)
    prova1 = float(match.group(2).replace(",", "."))
    prova2 = float(match.group(3).replace(",", "."))
    media = float(match.group(4).replace(",", "."))
    if int(codice) not in normalisti:
        if float(media)>=7 and float(prova1)>=6.5 and float(prova2)>=6.5:
            records.append({"prematricola":int(codice), "Punteggio I prova":float(prova1), "Punteggio II prova":float(prova2), "media":float(media)})

records.sort(key = lambda x: x["media"])
records.reverse()

# roba scritta da chatgpttttttttttttttttttttttttttttttttttttttttttttttt


dati = records

output_file = "tabella.txt"

# Intestazioni (aggiungo "Posizione")
headers = ["Posizione", "prematricola", "Voto I prova", "Voto II prova", "media"]
col_widths = [10, 15, 15, 15, 10]

with open(output_file, "w", encoding="utf-8") as f:
    # Intestazione
    header_line = "".join(h.ljust(w) for h, w in zip(headers, col_widths))
    f.write(header_line + "\n")
    f.write("-" * sum(col_widths) + "\n")

    # Riga per ogni dizionario, con posizione
    for i, riga in enumerate(dati, start=1):
        valori = [i, riga["prematricola"], riga["Punteggio I prova"], riga["Punteggio II prova"], riga["media"]]
        line = "".join(str(val).ljust(w) for val, w in zip(valori, col_widths))
        f.write(line + "\n")

print("Tabella salvata in", output_file)

