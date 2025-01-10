ladoA = 0
ladob = 0
ladoC = 0


def triangulo(a, b, c):
    if(a == b and a == c and b == c):
        return "equilátero"

    if(a == b or b == c or a==c):
        return "isósceles"

    return "escaleno"




ladoA = input("Digite o lado A")
ladoB = input("Digite o lado B")
ladoC = input("Digite o lado C")
print(triangulo(ladoA, ladoB, ladoC))


