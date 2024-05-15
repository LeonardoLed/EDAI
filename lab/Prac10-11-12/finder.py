from string import ascii_letters, digits
from itertools import product

chars = ascii_letters + digits
file = open("combinaciones.txt", 'w') # r, w, a, a+

def finder(con):
    i = 0 
    if 3 <= len(con) <= 4:
        for i in range(3,5):
            for comb in product(chars, repeat = i):
                i +=1
                test = "".join(comb)
                file.write(str(i) + "\t" + test + "\n" )
                if test == con:
                    print("contraseña descifrada.... en el intento numero: " + str(i))
                    return
    else:
        print("la contraseña debe ser entre 3 a 4 caracteres")


import getpass
from time import time

#con = input("dame una password de entre 3-4 caracteres")
p = getpass.getpass("Write password (it contains only digits and caracteres): ")

t0 = time()
finder(p)
print("Tiempo de ejecución {} [ms]".format((time()-t0)))
file.close()





