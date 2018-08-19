/*

Um eine abgeleitete Klasse definieren zu können, muss bekannt sein, 
wie die Methoden der Basisklasse implementiert sind.
- Falsch, die vorhandenen Methoden werden alle vererbt, unabhängig über das Wissen ihrer Implementierung.
- Die abgeleitete Klasse kann auch beliebig erweitert werden.

Eine abgeleitete Klasse erbt eine public-Methode der Basisklasse nicht, 
wenn sie selbst eine public -Methode mit dem gleichen Namen besitzt.
- Richtig, sie wird nicht vererbt sondern direkt überschrieben.

In einer abgeleiteten Klasse können nur die Methoden der Basisklasse redefiniert werden.
- Falsch, eine abgeleitete Klasse kann auch beliebig erweitert werden. (Attribute / Methoden)

Bei der Definition eines Destruktors einer abgeleiteten Klasse 
muss der Destruktor der Basisklasse explizit aufgerufen werden.
- Falsch, weil der Destruktor der abgeleiteten Klasse automatisch den Destruktor der Elternklasse aufruft.

Der Zugriff auf ein protected-Element einer Klasse X 
ist möglich innerhalb jeder Methode einer von X abgeleiteten Klasse.
- Richtig, alle Methoden der abgeleiteten Klasse haben Zugriff auf die protected Elemente der Elternklasse

*/