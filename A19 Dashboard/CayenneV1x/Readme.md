Temperatur- und Feuchtigkeitsregelmodul mit AM2301 Sensor

Produktelektrische Eigenschaften:
Feuchte-Messbereich:0%RH -99,9%
RH-Temperatur-Messbereich: -40°C bei 80°C
Auflösungsleistung: Luftfeuchtigkeit
0,1%RH, Temperatur 0,1 Messgenauigkeit: ±3%RH; ±0,5%°C
Regelgenauigkeit: 0,1%RH; ±0.1%°C
Bildwiederholfrequenz: 1S
Eingangsspannung: 5V-24V DC-Messeingang:
AM2301 Temperatur- und Feuchtigkeitsintegrierter Sensor
Ausgang: Zwei-Wege-10A-Relais
Umgebungsanforderungen: -10°C–60°C, Luftfeuchtigkeit 20%–85%
Gesamtenergieverbrauch: Ruhestrom≤20ma, Zugstrom≤50ma.

Funktion:
– Mit Temperatur- und Feuchtigkeitsregelfunktion.
– Kann die aktuelle Temperatur und Luftfeuchtigkeit in Echtzeit anzeigen.
– Mit Übergrenzungsalarmfunktion.
– Relais-Arbeitsanzeige-Funktion.
– Mit Netzteil Reverse-Schutz-Funktion. Der Controller funktioniert nicht, wenn das Netzteil an den Zähler angeschlossen ist.

Kontrollleuchte:

1. D8 ist die Temperaturrelaisanzeigelampe. Die Heizung (Kühlanlage) beginnt zu funktionieren, wenn das D8-Licht eingeschaltet ist.
2. D9 ist eine Feuchtigkeitsanzeige Relaisanzeige Lampe. Befeuchtungs-/Entfeuchtungsanlagen begannen zu funktionieren, wenn das D9-Licht eingeschaltet wurde.
3. Das Display zeigt den Echtzeit-Feuchtigkeitswert an, wenn das grüne D5-Licht eingeschaltet ist. Das Display zeigt den Echtzeit-Temperaturwert an, wenn die D5-Lampe ausgeht.
 
Funktionsbeschreibung:

1. Hochtemperaturstart – Kühlmodus:
Kühlgeräte beginnen zu arbeiten, wenn der Starttemperaturwert größer als der Stopptemperaturwert ist und die Temperaturmessung größer oder gleich der Anfangstemperatur ist. Kühlgeräte funktionieren nicht mehr, wenn die Temperaturmessung kleiner oder gleich der Stopptemperatur ist.
Stellen Sie beispielsweise die Starttemperatur auf 20°C ein, die Stopptemperatur ist 15°C, D8-Licht ist eingeschaltet und Kühlgeräte funktionieren, wenn die Erfassungstemperatur größer oder gleich 20°C ist. D8-Licht ging aus und Kühlgeräte werden nicht mehr funktionieren, wenn der Temperaturwert weniger als 15°C beträgt. 

2. Niedrigtemperaturstart – Heizmodus: 
Heizgeräte beginnen zu arbeiten, wenn der Starttemperaturwert kleiner als der Stopptemperaturwert ist und die Temperatur kleiner oder gleich der Anfangstemperatur ist. Heizgeräte funktionieren nicht mehr, wenn die Prüftemperatur größer oder gleich der Stopptemperatur ist.
Stellen Sie beispielsweise die Starttemperatur auf 15°C ein, Stopptemperatur ist 20°C. D8-Leuchten werden eingeschaltet und Heizgeräte beginnen zu funktionieren, wenn der Temperaturmesswert kleiner oder gleich 15°C ist. D8-Licht ging aus und Heizgeräte, um nicht mehr zu arbeiten, wenn der Temperaturmesswert größer oder gleich der Stopptemperatur ist. 

3. Hoher Feuchtigkeitsstart – Desiccant-Modus:
Das System bestimmt automatisch den Modus der Entfeuchtung, wenn der beginnende Feuchtigkeitswert höher ist als der Wert der Stop-Feuchtigkeit.

In diesem Modus, Entfeuchtungsgeräte zu starten Arbeit, wenn Feuchtigkeitserkennung größer oder gleich dem Beginn der Feuchtigkeit ist. Entfeuchtungsanlagen funktionieren nicht mehr, wenn die Feuchtigkeitserkennung kleiner oder gleich der Stop-Feuchtigkeit ist.
Legen Sie beispielsweise die Startfeuchte auf 60% RH fest, Stop-Feuchtigkeit ist 40%RH. Die Anzeigeleuchte D9 leuchtet ein und entfeuchtet die Entfeuchtungsanlagen, wenn der erkannte Feuchtigkeitswert größer oder gleich 60% RH ist. Kontrollleuchte D9 ging aus und Entfeuchtungsgeräte nicht mehr funktionieren, wenn Feuchtigkeitserkennungswert kleiner oder gleich 40% RH ist. 

4. Niedrige Luftfeuchtigkeit start –
Befeuchtungsmodus Das System wechselt automatisch in den Befeuchtungsmodus, wenn die eingestellte Startfeuchte kleiner als der Wert des Feuchtigkeitswertes ist.

In diesem Modus begann die Befeuchtungseinrichtung zu funktionieren, wenn die Feuchtigkeitserkennung kleiner oder gleich dem Beginn der Luftfeuchtigkeit ist. Befeuchtungsanlagen funktionieren nicht mehr, wenn die Feuchtigkeitserkennung größer oder gleich dem Beginn der Luftfeuchtigkeit ist.
Zum Beispiel, Stellen Sie die Startfeuchtigkeit auf 40%RH, Stop Luftfeuchtigkeit ist 60%RH, Anzeigeleuchte D9 ist eingeschaltet und Befeuchtungsgeräte in die Arbeit, wenn die Feuchtigkeitserkennung Wert kleiner oder gleich 40% RH ist. Kontrollleuchte D9 ging aus und Befeuchtungsgeräte, um die Arbeit zu stoppen, ist der Feuchtigkeitserkennungswert größer oder gleich 60% RH.

5. Temperaturalarm-Modus: Anzeige zeigt Axx (Standard ist A00) und blinkt im Boot 3 Sekunden, Sie können "+" und "-" verwenden, um den Alarmmodus einzustellen, Alarmmodi sind wie folgt definiert: A00: Alarmfunktion aus (Standard) A01: die derzeit Etektion der Feuchtigkeit über die Starttemperatur oder Stopptemperatur von 1°C, Summer Alarm.

A02: die derzeit detektion von Feuchtigkeit über die Starttemperatur oder Stopptemperatur von 2°C, Summer Alarm.
A03: die derzeit detektion von Feuchtigkeit über die Starttemperatur oder Stopptemperatur von 3°C, Summer Alarm.
und so weiter, max kann A30 eingestellt werden.
Zum Beispiel ,Einstellen Alarmmodus A03, Starttemperatur ist20°C, Stop-Temperatur ist 30°C, Buzzer-Sound-Alarm, wenndie gemessene Temperatur über 33°C oder unter 17°C ist.
Konkrete Einstellungsmethode:

Hinweis: Die folgenden Einstellungen werden automatisch in EEPROM 1 gespeichert. 

Starttemperatur einstellen:
Lange s-Taste für 3 Sekunden drücken, Rotlicht D3 beginnen zu blinken. Anzeige zeigt Starttemperaturwert in diesem Moment, Drücken Sie + und – Taste, um diesen Wert anzupassen, Lange drücken ist kontinuierliche Anpassung. Drücken Sie lange S-Taste, um die Einstellung nach Abschluss der Einstellung
oder automatischen Ausgang ohne Schlüsselaktion in 10S. 2 zu beenden. 

Stopptemperatur einstellen:
Lange s-Taste für 3 Sekunden drücken, Rotlicht D3 beginnen zu blinken. Kurzes Drücken Sie set Taste noch einmal und rote LED D3 lange hell, Anzeige zeigt Stopp-Temperatur-Wert in diesem Moment, drücken + und – Taste, um diesen Wert einzustellen, Lange drücken ist kontinuierliche Einstellung. Drücken Sie lange S-Taste, um die Einstellung nach Abschluss der Einstellung
oder automatischen Ausgang ohne Schlüsselaktion in 10S. 3 zu beenden. 

Startfeuchtigkeit einrichten:
Lange s-Taste für 3 Sekunden drücken, Rotlicht D3 beginnen zu blinken. Drücken Sie zweimal die SET-Taste und die rote LED D4 blinkt. Der Bildschirm zeigt den Startfeuchtewert an, dieser Wert kann durch Drücken der + und – Tasten eingestellt werden, langes Drücken ist kontinuierliche Einstellung. Drücken Sie lange S-Taste, um die Einstellung nach Abschluss der Einstellung
oder automatischen Ausgang ohne Schlüsselaktion in 10S. 4 zu beenden. 

Stellen Sie die Stop-Feuchtigkeit Lange drücken Sie S-Taste für 3 Sekunden, Rotlicht D3 beginnen zu blinken. Drücken Sie dreimal die SET-Taste und die rote LED D4 blinkt. Display-Bildschirm zeigt den Wert der Stop-Feuchtigkeit zu diesem Zeitpunkt, dieser Wert kann durch Drücken der + und – Tasten eingestellt werden, langes Drücken ist kontinuierliche Einstellung. Drücken Sie lange S-Taste, um die Einstellung nach Abschluss der Einstellung
oder automatischen Ausgang ohne Schlüsselaktion in 10S. 5 zu beenden. 

Stellen Sie das Temperaturmodell Lange drücken S-Taste für 3 Sekunden, Rotlicht D3 beginnen zu blinken. Kurzes Set-Taste viermal wieder und rote LED D3 und LED D4 beginnen gleichzeitig zu blinken. Zu diesem Zeitpunkt zeigt der Bildschirm "C" oder "F", dieser Wert kann durch Drücken der + und – Tasten eingestellt werden. C bedeutet, dass das aktuelle Temperaturmodell Grad Celsius ist, F bedeutet, dass das aktuelle Temperaturmuster Fahrenheit ist. Drücken Sie lange S-Taste, um die Einstellung nach Abschluss der Einstellung
oder automatischen Ausgang ohne Schlüsselaktion in 10S. 6 zu beenden. 

Einstellen des Alarmmodus Siehe auch "Funktionsbeschreibung" 5.Temperatur-Alarmmodus.

Stellen Sie die Werkseinstellungen Hold + wieder her und – drücken Sie die Taste und starten Sie dann, Display-Bildschirmanzeige "rrrr", Alle Einstellungen werden nach Buzzer-Sound dreimal wieder in die Werkseinstellungen zurückgesetzt.
