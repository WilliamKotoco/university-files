import sys

def process_genetic_file(input_file, output_file):
    valid_chars = {'A', 'C', 'G', 'T'}
    concatenated_sequence = ""

    with open(input_file, 'r') as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) < 2:
                continue  # Ignorar linhas mal formatadas
            sequence = parts[0]  # A sequência genética está antes do número
            filtered_sequence = ''.join(c for c in sequence if c in valid_chars)
            concatenated_sequence += filtered_sequence

    with open(output_file, 'w') as file:
        file.write(concatenated_sequence)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Uso: python script.py arquivo_entrada.txt arquivo_saida.txt")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    
    process_genetic_file(input_file, output_file)
    print(f"Sequência processada salva em {output_file}")
