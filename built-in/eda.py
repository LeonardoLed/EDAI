
class Pila:

	"""
	Programación de una pila
	en python. Va tener tres funciones:

	a) Verificar si esta vacía
	b) Push (Apilar)
	c) Pop (Desapilar)

	"""

	def __init__(self):
		self.items = []

	def es_vacia(self):
		return self.items == []

	def apilar(self, x):
		# Agregar el elemento x a la pila
		self.items.append(x)

	def desapilar(self):
		# Devuelve el elemento de la pila y lo elimina
		try:
			return self.items.pop()
		except IndexError:
			raise ValueError("La pila esta vacia")

	def __str__(self):
		status = ""
		inodo_stack = 0

		for i in self.items:
			status += "i_stack[" + str(inodo_stack) + "]: " + " -> " + str(i) + "\n"
			inodo_stack +=1

		return status

class Cola:

	"""
	Programación de una cola
	en python. Va tener tres funciones:

	a) Verificar si esta vacía
	b) Push (Encolar)
	c) Pop (Desencolar)

	"""

	def __init__(self):
		self.items = []

	def es_vacia(self):
		return self.items == []

	def encolar(self, x):
		# Agregar el elemento x a la cola
		self.items.append(x)

	def desencolar(self):
		# Devuelve el elemento de la cola y lo elimina
		try:
			return self.items.pop(0)
		except IndexError:
			raise ValueError("La cola esta vacia")

	def __str__(self):
		status = ""
		inodo_stack = 0

		for i in self.items:
			status += "i_queue[" + str(inodo_stack) + "]: " + " -> " + str(i) + "\n"
			inodo_stack +=1

		return status
