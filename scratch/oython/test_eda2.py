from eda_nodo import Pila

def main():

    #Pila
    p = Pila(10)
    p.apilar(4)
    p.apilar(5)
    p.apilar("gato")
    print(p)
    p.desapilar()
    print(p)
    p.desapilar()
    print(p)
    p.desapilar()
    print(p)




if __name__ == "__main__":
    main()
