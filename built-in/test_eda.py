from eda import Pila
from eda import Cola

def main():
    #Pila
    p = Pila()
    print(p)
    print(p.es_vacia())
    p.apilar(4)
    p.apilar(5)
    p.apilar("gato")
    print(p)
    p.desapilar()
    print(p)

    #Cola
    c = Cola()
    c.encolar(2)
    c.encolar(4)
    c.encolar(10)
    print(c)
    c.desencolar()
    print(c)


if __name__ == "__main__":
    main()
