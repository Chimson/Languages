Set-Location "C:\Users\Benso\Programming\Personal\Languages\Labs\Winter23\CSC-242-Miller\lab9\Grading"
$files = Get-ChildItem -Name -Include *.zip
# $files = Sort-Object $files 
foreach ($f in $files) {

  $ListWords =  $f.Split("-")
  $name = $ListWords[2]
  $name = $name.Trim()  # trim leading and ending whitespace
  Expand-Archive $f -DestinationPath "./$name"

  Set-Location "C:\Users\Benso\Programming\Personal\Languages\Labs\Winter23\CSC-242-Miller\lab9\Grading"
}


Set-Location "C:\Users\Benso\Programming\Personal\Languages\Labs\Winter23\CSC-242-Miller\lab9"

