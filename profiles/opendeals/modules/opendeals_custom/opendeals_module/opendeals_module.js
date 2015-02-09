(function($){
  $(document).ready(function(){
  deals_city = $.cookie('deals_city');
  if(deals_city != '' && deals_city != null){
    deals_city = '/all-deals/'+deals_city;
    $('.view-cities-list select option').removeAttr('selected');
    $('.view-cities-list select option[value$="'+deals_city+'"]').attr('selected','selected');
  }

  $('.view-cities-list select').unbind().bind('change', function(){
    if(this.value != '' && this.value != null) {
    parts = (this.value).split('::');
    parts[1] = parts[1].split('/');
        customvalue = parts[1].pop(-1);
    $.cookie('deals_city', customvalue, { expires: 30, path: Drupal.settings.basePath});
    window.location.reload();
    return false;
  } else {
    $.cookie('deals_city', null, {expires: -10, path: Drupal.settings.basePath});
    window.location.reload();
    return false;
  }
  });
  });
})(jQuery);