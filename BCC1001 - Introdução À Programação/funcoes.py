PI = 3.14159

raio = 0
area = 0
volume = 0

def esfera_area(raio):
    area = 4*PI*(raio*raio)
    return area


def esfera_volume(raio):
    volume = (4*PI*(raio*raio*raio))/3
    return volume

raio = int(input("Digite o valor do raio: "))
area = esfera_area(raio)
volume = esfera_volume(raio)
print(area)
print(volume)

