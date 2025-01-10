def verificar_infração_velocidade(velocidade_maxima, velocidade_motorista):
    # Calcular a tolerância
    if velocidade_maxima <= 100:
        tolerancia = 7
    else:
        tolerancia = velocidade_maxima * 0.07

    # Velocidade máxima permitida considerando a tolerância
    limite_tolerado = velocidade_maxima + tolerancia

    if velocidade_motorista <= limite_tolerado:
        return 0  # Nenhuma infração
    elif velocidade_motorista <= velocidade_maxima * 1.2:
        return 2  # Infração média
    elif velocidade_motorista <= velocidade_maxima * 1.5:
        return 3  # Infração grave
    else:
        return 4  # Infração gravíssima

def calcular_multa(tipo_infracao):
    valorMulta = 0
    if tipo_infracao == 2:
        valorMulta = 130.16
        return valorMulta
    elif tipo_infracao == 3:
        valorMulta = 195.23
        return valorMulta
    elif tipo_infracao == 4:
        valorMulta = 293.47
        return valorMulta
    else:
        return 0

def main():
    # Entrada de dados
    velocidade_maxima = float(input("Informe a velocidade máxima da via (km/h): "))
    velocidade_motorista = float(input("Informe a velocidade do motorista (km/h): "))

    # Verificar o tipo de infração
    tipo_infracao = verificar_infração_velocidade(velocidade_maxima, velocidade_motorista)

    if tipo_infracao == 0:
        print("Parabéns, bom motorista!")
    else:
        # Calcular o valor da multa
        multa = calcular_multa(tipo_infracao)
        print(f"Você cometeu uma infração e precisa pagar uma multa de R$ {multa:.2f}")

if __name__ == "__main__":
    main()
