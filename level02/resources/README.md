# level02

## Contexte

On trouve le fichier `level02.pcap` dans le home de `level02`.

## Recherche

Une recherche rapide nous apprend que les fichiers `.pcap` correspondent à des captures de trafic réseau.

On peut les ouvrir avec des outils comme **Wireshark** pour voir les échanges entre les machines.

## Vulnérabilité

La communication utilise le protocole **Telnet**.

Telnet est un protocole ancien qui n'utilise pas de chiffrement : toutes les données échangées passent en clair. Il est donc possible de voir directement ce qui est envoyé, y compris un mot de passe.

## Exploitation

On ouvre la capture avec Wireshark et on regarde les échanges TCP.

En remettant les données dans l'ordre, on retrouve la saisie du mot de passe :

```
%%& #'$& #'$ #' 38400,38400#SodaCan:0'DISPLAYSodaCan:0xterm"!""bb	B
1!""!"""	

Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

wwwbugs login: lleevveellXX
Password: ft_wandrNDRelL0L

Login incorrect
wwwbugs login:
```

On remarque cependant que certains caractères sont affichés comme `7F`.

Ces caractères correspondent à la touche `DEL` (suppression). L'utilisateur les a utilisés pour effacer des caractères pendant sa saisie.

Après avoir retiré les caractères supprimés, on obtient le vrai mot de passe :

```text
ft_waNDReL0L
```

On peut ensuite se connecter à `flag02` et récupérer le flag avec `getflag` :

```text
kooda2puivaav1idi4f57q8iq
```

## Ressources

- Wireshark
- `tshark`