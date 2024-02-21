
class nodoPila(object):
    """ Clase nodo de una pila"""
    info, sig = None, None

class Pila(object):
    """Clase Pila"""

    def __init__(self, n):
        """ Se crea una pila vacia"""
        self.ls = 0
        self.li = n
        self.tamanio = 0
        self.T = None
        self.nodo_cima = None

    def apilar(self, dato):
        """ Operacion Push en Pila """


        if self.T == self.ls:
            print("Pila llena")
        else:
            if self.T == None:

                #creamos una celda o nodo incial
                nodo = nodoPila()
                nodo.info = dato
                nodo.sig = self.nodo_cima

                #actualizamos datos de la pila
                self.tamanio += 1
                self.nodo_cima = nodo
                self.T = self.li

            else:

                nodo = nodoPila()
                nodo.info = dato
                nodo.sig = self.nodo_cima

                self.tamanio += 1
                self.nodo_cima = nodo

                self.T -= 1

        print(self.T, self.ls, dato)

    def desapilar(self):
        """ Operacion Pop en Pila """

        if self.T == None:
            print("Pila esta vacia")
            pass
        else:
            if self.T == self.li:

                x = self.nodo_cima.info
                self.nodo_cima = None

                #actualizamos datos de la pila
                self.tamanio -= 1
                self.T = None

            else:
                x = self.nodo_cima.info
                self.T +=  1
                self.nodo_cima = self.nodo_cima.sig
                self.tamanio -= 1

            print("sale de la Pila: " + str(x))
            return x

    def __str__(self):
        status = ""
        inodo_stack = self.tamanio
        inodo = self.nodo_cima
        for i in range(self.tamanio, 0, -1):
            if inodo is not None:
                status += "i_stack[" + str(inodo_stack) + "]: " + " -> " + str(inodo.info) + "\n"
                inodo = inodo.sig
                inodo_stack -=1

        if self.tamanio == 0:
            print("pila vacia =P")

        return status
