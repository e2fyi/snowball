(function(ElasticMeow, Snowball) {
  const _snowball = Snowball.cwrap('stem', 'string', ['string']);
  const snowball = function(str) {
    if (Array.isArray(str)) return _snowball(str.join(' ')).split(' ');
    return _snowball(str);
  };

  ElasticMeow.stemmer = ElasticMeow.stemmer || {};
  ElasticMeow.stemmer.snowball = snowball;

})(window.ElasticMeow = window.ElasticMeow || {}, Snowball);
