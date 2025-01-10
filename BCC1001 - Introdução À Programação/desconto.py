import random
import time

def calcular_desconto(tipo_produto, valor_produto):
    """
    Calcula o desconto baseado no tipo do produto e no sorteio de números.
    Retorna o percentual de desconto e o valor final com desconto.
    """
    if tipo_produto == "eletrodoméstico":
        num1 = random.randint(0, 30)
        num2 = random.randint(0, 30)
    elif tipo_produto == "informática":
        num1 = random.randint(5, 20)
        num2 = random.randint(5, 20)
    elif tipo_produto == "alimentação saudável":
        num1 = random.randint(10, 50)
        num2 = random.randint(10, 50)
    else:
        return 5, valor_produto * 0.95  # Desconto fixo de 5%

    diferenca = abs(num1 - num2)
    percentual_desconto = min(diferenca, 50)  # Limita o desconto máximo a 50%
    valor_com_desconto = valor_produto * (1 - percentual_desconto / 100)

    return percentual_desconto, valor_com_desconto

def main():
    # Solicita o tipo de produto ao usuário
    tipo_produto = input("Informe o tipo do produto (eletrodomésticos, informática, alimentação saudável): ").strip().lower()

    # Calcula o valor do produto com base no timestamp atual
    timestamp = int(time.time())
    print("timestamp", timestamp)
    print("timestamp1", timestamp // 100000)
    print("timestamp2", (timestamp // 100000) % 2000)
    valor_produto = (timestamp // 100000) % 2000  # Limita o valor do produto a 2000

    # Calcula o desconto
    percentual_desconto, valor_com_desconto = calcular_desconto(tipo_produto, valor_produto)

    # Exibe os resultados
    print(f"{valor_produto}")
    print(f"{percentual_desconto}")
    print(f"{valor_com_desconto:.2f}")

if __name__ == "__main__":
    main()
