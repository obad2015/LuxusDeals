(function($) {
	$(document).ready(function() {
		if ($('#nodedealtitle').length > 0 && $('#sidebar').length > 0 ) { // Deletes current deal from sidebar
			$('#sidebar .views-row .views-field-title span a').each(function() { 
				if ($(this).html() == $('#nodedealtitle').html() || $(this).html() == $('#nodedealtitle a').html()) {
					$(this).parents('.views-row').css('display','none');
				}
			});
		}
		
	});
})(jQuery);
