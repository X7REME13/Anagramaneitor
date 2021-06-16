def es_anagrama_facil(cad1, cad2):
    if cad1 == cad2 or len(cad1) != len(cad2): return False
    list1 = list(cad1)
    list2 = list(cad2)
    cont = 0
    for i, letra2 in enumerate(list1):
        for j, letra1 in enumerate(list2):
            if letra1 == letra2:
                list2[j] = '!'
                cont += 1
                break;

    return len(cad1) == cont

archivo = 'dicc.txt'
with open(archivo, encoding='utf8') as f:
    lines = f.readlines()


def criterio(e):
    return len(e)


lines.sort(key=criterio)
with open("diccionariasasdasdasdasd.txt","w", encoding='utf-8') as filesave:
    for line in lines:
        filesave.write(line)
