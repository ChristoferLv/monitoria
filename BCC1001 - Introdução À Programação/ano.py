ano = 0


def bissexto(ano):
    ano = int(ano)
    if((ano % 400) == 0):
        print("Este ano é bissexto e possui 366 dias")
        return (True)
    elif((ano % 4) == 0 and (ano % 100) != 0):
        print("Este ano é bissexto e possui 366 dias")
        return (True)
    else:
        print("Este ano possui 365 dias")
        return (False)




ano = int(input("Digite o ano: "))
print(bissexto(ano))